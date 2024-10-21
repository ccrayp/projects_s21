sed -i "s/$2/$3/g" $1
size=$(stat -c%s $1)
currDate=$(date +"%Y-%m-%d %H:%M")
currSHAsumm=$(sha256sum "$1" | awk '{ print $1 }')
echo "src/$1 - $size - $currDate - $currSHAsumm - sha256" >> files.log
