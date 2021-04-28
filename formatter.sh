#!/bin/bash

function usage {
    echo "Usage: $0 DIR..."
    exit 1
}

if [ $# -eq 0 ]; then
    usage
fi

FMT=""

for clangfmt in clang-format{,-{4,3}.{9,8,7,6,5,4,3,2,1,0}}; do
    if which "$clangfmt" &>/dev/null; then
        FMT="$clangfmt"
        break
    fi
done

if [ -z "$FMT" ]; then
    echo "failed to find clang-format"
    exit 1
fi

for dir in "$@"; do
    if [ ! -d "${dir}" ]; then
        echo "${dir} is not a directory"
        usage
    fi
done

find-dominating-file() {
    if [ -r "$1"/"$2" ]; then
        return 0
    fi
    if [ "$1" = "/" ]; then
        return 1
    fi
    find-dominating-file "$(realpath "$1"/..)" "$2"
    return $?
}

for dir in "$@"; do
    pushd "${dir}" &>/dev/null
    if ! find-dominating-file . .clang-format; then
        echo "Failed to find dominating .clang-format starting at $PWD"
        continue
    fi
    find . \
         \( -name '*.c' \
         -o -name '*.cc' \
         -o -name '*.cpp' \
         -o -name '*.h' \
         -o -name '*.hh' \
         -o -name '*.hpp' \) \
         -exec "${FMT}" -i '{}' \;
    popd &>/dev/null
done