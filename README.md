# Projeto final INF01151
# SyncBox - Sistema de Sincronização de Arquivos

Um serviço de sincronização de arquivos similar ao Dropbox, desenvolvido em C/C++, que permite compartilhar e sincronizar arquivos entre dispositivos de um mesmo usuário. O sistema utiliza uma arquitetura cliente-servidor com suporte a múltiplos usuários e dispositivos, garantindo consistência e persistência dos dados.

---

## Tecnologias Utilizadas
- **Linguagens**: C/C++
- **Comunicação**: TCP sockets
- **Concorrência**: Threads (pthreads), mutex, semáforos
- **Monitoramento de arquivos**: `inotify` (Unix)
- **Persistência**: Armazenamento em diretórios locais do servidor
- **Sistema Operacional**: Unix/Linux

---

## Funcionalidades Principais
### Servidor
- Suporte a **múltiplos usuários** e sessões simultâneas (até 2 dispositivos por usuário).
- Sincronização automática de arquivos no diretório `sync_dir` entre dispositivos.
- Persistência de dados: arquivos e diretórios são restaurados após reinicialização do servidor.
- Gerenciamento concorrente seguro com mutex/semáforos.

### Cliente
- Interface de linha de comando (CLI) para interação com o servidor.
- Comandos para upload, download, exclusão, listagem de arquivos e mais.
- Monitoramento automático do diretório `sync_dir` via `inotify` para detectar alterações.
- Sincronização bidirecional em tempo real com o servidor.

---

## Requisitos
### Funcionais
- Autenticação de usuário por nome.
- Sincronização de arquivos entre dispositivos do mesmo usuário.
- Suporte a comandos CLI: `upload`, `download`, `delete`, `list_server`, `list_client`, `exit`.
- Criação automática do `sync_dir` no cliente ao iniciar uma sessão.
- Exibição de metadados (modification time, access time, etc.) nos comandos de listagem.

### Sistema
- Sistema operacional Unix/Linux.
- Compilador C++ (e.g., `g++` versão 11 ou superior).
- Biblioteca `pthread` e `inotify-tools` instaladas.

