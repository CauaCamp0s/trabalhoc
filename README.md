# Sistema de Gerenciamento de Alunos

Este projeto é um **sistema de gerenciamento de alunos** desenvolvido em **C** como parte de um trabalho da faculdade. Ele permite cadastrar, alterar, listar e verificar a situação de aprovação ou reprovação dos alunos com base em suas notas e frequência.

---

## 💻 Funcionalidades

- **Cadastrar aluno**: Insere um novo aluno no sistema com matrícula, notas e número de faltas.
- **Alterar dados do aluno**: Permite modificar as informações de um aluno já cadastrado.
- **Listar alunos cadastrados**: Mostra uma lista completa de todos os alunos registrados.
- **Listar alunos aprovados**: Exibe os alunos aprovados com média ≥ 7 e até 15 faltas.
- **Listar alunos reprovados por média**: Mostra os alunos com média < 6.
- **Listar alunos reprovados por faltas**: Lista os alunos com mais de 27 faltas.
- **Menu interativo**: Interface de terminal para navegar pelas opções disponíveis.

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**: Para desenvolvimento do sistema.
- **Bibliotecas padrão do C**: `stdio.h`, `stdlib.h`, `string.h`.

---

## 📂 Estrutura do Código

- **`imprimir_menu`**: Exibe o menu de opções para o usuário.
- **`cadastrarAluno`**: Adiciona um novo aluno ao sistema.
- **`alterarAluno`**: Modifica os dados de um aluno existente.
- **`listarAlunos`**: Exibe todos os alunos cadastrados.
- **`listarAlunosAprovados`**: Mostra os alunos aprovados.
- **`listarAlunosReprovadosMedia`**: Lista alunos reprovados por média.
- **`listarAlunosReprovadosFalta`**: Exibe alunos reprovados por excesso de faltas.
- **`buscarAluno`**: Função auxiliar para encontrar um aluno por matrícula.

---

## ⚙️ Como Executar

1. **Compilar o código**:  
   Use um compilador de C, como o GCC:  
   ```bash
   gcc -o gerenciamento_alunos gerenciamento_alunos.c
Executar o programa:
./gerenciamento_alunos
Interagir com o menu:
Navegue pelo menu para utilizar as funcionalidades do sistema.

## 📝 Regras do Sistema
Média de Aprovação: Alunos precisam de média ≥ 7 e até 15 faltas.
Reprovação por Média: Alunos com média < 6 são reprovados.
Reprovação por Faltas: Alunos com mais de 27 faltas são reprovados.
Limite de Alunos: O sistema suporta até 50 alunos.
## 🛠️ Melhorias Futuras
Adicionar persistência dos dados em arquivo.
Implementar um sistema de exclusão de alunos.
Criar relatórios detalhados para exportação.
Melhorar validações de entrada de dados.
## 🧑‍💻 Autor
Este projeto foi desenvolvido como parte de um trabalho acadêmico.
Cauã Campos.
📧 Email: caua.campos.job@gmail.com
