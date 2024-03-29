script_folder="/home/evangelia/clionProjects/obc-software-harmony-changed/cmake-build-debug/build/Debug/generators"
echo "echo Restoring environment" > "$script_folder/../../../build/Debug/generators/deactivate_conanrunenv-debug-armv7.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/../../../build/Debug/generators/deactivate_conanrunenv-debug-armv7.sh"
    else
        echo unset $v >> "$script_folder/../../../build/Debug/generators/deactivate_conanrunenv-debug-armv7.sh"
    fi
done

