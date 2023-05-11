echo "echo Restoring environment" > "/home/tiger/XNode/ConanExample/build/deactivate_conanrunenv-release-x86_64.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "/home/tiger/XNode/ConanExample/build/deactivate_conanrunenv-release-x86_64.sh"
    else
        echo unset $v >> "/home/tiger/XNode/ConanExample/build/deactivate_conanrunenv-release-x86_64.sh"
    fi
done

