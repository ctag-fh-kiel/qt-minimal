file(GLOB DISHSOURCES Dish*.cpp)

# automatically populate factory class
set(DISH_INCLUDES "")
set(DISH_TYPES "")
set(BIG_IF "")
foreach (VAR ${DISHSOURCES})
    # filename without extension
    get_filename_component(MYFILE_WITHOUT_EXT ${VAR} NAME_WLE)
    string(REGEX REPLACE "Dish+" "" DISH_NAME ${MYFILE_WITHOUT_EXT})
    set(DISH_INCLUDES "${DISH_INCLUDES}#include \"${MYFILE_WITHOUT_EXT}.h\"\n")
    # prepare big if variable for factory
    set(BIG_IF "${BIG_IF}if(type.compare(\"${DISH_NAME}\") == 0) return std::make_unique<${MYFILE_WITHOUT_EXT}>();\n")
    set(DISH_TYPES "${DISH_TYPES}\"${DISH_NAME}\",")
endforeach ()

#message(WARNING ${BIG_IF})
#message(WARNING ${DISH_INCLUDES})
configure_file(DishFactory.h.in DishFactory.h @ONLY)

add_library(dishlib ${DISHSOURCES})
target_include_directories(dishlib PUBLIC . ${CMAKE_BINARY_DIR}/dishlib)