/*
O módulo de gerenciamento de arquivos é responsável por gerenciar os diretórios de cada usuário, os
dados e metadados dos arquivos armazenados. Para isso, deve ser mantido um diretório para cada
cliente, que pode ser identificado pelo próprio identificador do usuário.
Gerencia operações de arquivos (criar, deletar, listar).
Mantém metadados (MAC times) e sincroniza alterações.
Usa mutex para acesso concorrente ao diretório do usuário.
*/

#include <string>

