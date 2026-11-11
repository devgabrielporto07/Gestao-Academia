# 🏋️ Sistema de Gestão de Academia

## Sobre o projeto

O **Sistema de Gestão de Academia** é um projeto acadêmico simples e prático, desenvolvido para organizar as principais rotinas de uma academia:

- 👤 **Alunos** — cadastro, consulta, edição e remoção
- 📋 **Planos** — mensal, trimestral, anual etc., com valores e duração
- 📝 **Matrículas** — vínculo entre aluno e plano, com data de início e situação
- 💰 **Pagamentos** — registro de mensalidades e controle de pendências
- 📅 **Frequência** — registro de presença dos alunos

O núcleo do sistema é escrito em **C**, roda no **terminal** e segue a ideia de **modularização**: cada funcionalidade fica em seu próprio módulo (`.c` / `.h`), e todos são integrados em um único `main.c`.
Em paralelo, está sendo desenvolvida uma **interface gráfica em C#**.

> 🚧 Projeto em desenvolvimento.

## Acesse o projeto

Clone o repositório:

```bash
git clone https://github.com/<usuario>/<repositorio>.git
cd <repositorio>
```

Compile e execute a versão de terminal (C):

```bash
gcc *.c -o academia
./academia
```

> Os comandos podem mudar conforme a estrutura de pastas evoluir.

## Preview

> Em breve: capturas de tela da versão de terminal e da interface gráfica.

## Tecnologias Utilizadas

| Tecnologia | Uso |
|------------|-----|
| ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) | Lógica principal do sistema (terminal) |
| ![C#](https://img.shields.io/badge/C%23-512BD4?style=for-the-badge&logo=dotnet&logoColor=white) | Interface gráfica |

## Licença

Este projeto está sob a licença **MIT**. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## Equipe

| Integrante | GitHub |
|------------|--------|
| Alfredo Alves | [@Alfredinkapps](https://github.com/Alfredinkapps) |
| Gabriel Porto | [@devgabrielporto07](https://github.com/devgabrielporto07) |
| Sara Arruda | [@Sararruda](https://github.com/Sararruda) |
| Daniel Mota | [@danielRMota](https://github.com/danielRMota) |
| Luiz Kaynan | [@kaynan-CC](https://github.com/kaynan-CC) |
| Pedro Vinicius | Interface gráfica (C#) |

**Orientadora:** Professora Ana Paula do Ó — [@profanacgpb](https://github.com/profanacgpb)

## Contato

Para dúvidas, sugestões ou problemas, entre em contato com a equipe ou abra uma [issue](../../issues) no repositório.
