cmake_minimum_required(VERSION 3.10)
project(MeuProjeto CXX)

# Adiciona o diretório onde estão os seus arquivos de código-fonte
add_subdirectory(cmake)

# Especifique onde devem ser colocados os executáveis compilados
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Adicione outros comandos do CMake conforme necessário
