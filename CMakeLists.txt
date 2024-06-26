cmake_minimum_required(VERSION 3.10)
project(HotelDescansoGarantido CXX)

# Adicione os subdiretórios relevantes
add_subdirectory(clientes)
add_subdirectory(funcionarios)
add_subdirectory(quartos)
# Adicione mais subdiretórios conforme necessário

# Pode ser necessário incluir bibliotecas externas, defina aqui

# Exemplo de configuração para geração de executável principal
add_executable(HotelDescansoGarantido main.cpp)

# Link contra bibliotecas externas, se necessário
# target_link_libraries(HotelDescansoGarantido <nome_da_biblioteca>)

# Defina outras configurações do CMake conforme necessário
