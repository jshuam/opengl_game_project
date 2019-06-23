file(REMOVE_RECURSE
  "libgl.pdb"
  "libgl.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/gl.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
