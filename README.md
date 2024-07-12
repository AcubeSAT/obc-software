# OBC Software Repository

`git submodule update --init --recursive`

ETL error? Go to `cross-platform-software` --> `CMakeLists.txt` and remove:
```
find_package(etl CONFIG REQUIRED)
find_package(logger CONFIG REQUIRED COMPONENTS log_common log_x86)
find_package(ecss-services CONFIG REQUIRED COMPONENTS common)
```

and `etl` from

```
target_link_libraries(common_cross PRIVATE common etl log_common)
```