SRC_DIR="../src"
THIRDPARTY_DIR="Eigen"

reset

rm -r .build
mkdir .build
cd .build

g++ -std=c++11 -Ofast -w -I$THIRDPARTY_DIR  -o app_boids $SRC_DIR/*.cpp -lopengl32 -lglu32 -lGLUT

./app_boids