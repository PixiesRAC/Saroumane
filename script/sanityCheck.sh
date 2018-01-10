if [ ! -d "../log" ];then
echo "Log folder not present, creation of it";
mkdir ../log
fi

if [ ! -d "../third_party" ];then
mkdir ../third_party
cd ../third_party/.
fi

cd ../third_party/.

if [ ! -d "../third_party/googletest" ];then
git clone https://github.com/google/googletest.git
cd googletest
cmake .
cd ..
fi


if [ ! -d "../third_party/property_tree" ];then
git clone https://github.com/boostorg/property_tree.git
fi


if [ ! -d "../third_party/format" ];then
git clone https://github.com/boostorg/format.git
fi

