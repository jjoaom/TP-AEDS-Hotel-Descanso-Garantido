# CMakeLists.txt dentro da pasta source
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_executable(HotelDescansoGarantido ${SOURCES} ${HEADERS})

# Configurações adicionais conforme necessário, como linkar bibliotecas externas
