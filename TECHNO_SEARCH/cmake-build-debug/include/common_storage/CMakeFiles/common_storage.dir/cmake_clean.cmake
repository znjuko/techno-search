file(REMOVE_RECURSE
  "libcommon_storage.a"
  "libcommon_storage.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/common_storage.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
