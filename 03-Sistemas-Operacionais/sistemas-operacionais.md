# 03 — SISTEMAS OPERACIONAIS

## 3.1 Virtualização e Ambiente de Servidores

A FH Enterprise utiliza o Proxmox Virtual Environment (VE) como plataforma de virtualização no Datacenter da Matriz. A utilização de virtualização permite executar diferentes servidores virtuais em um único servidor físico, melhorando o aproveitamento dos recursos computacionais e facilitando o gerenciamento da infraestrutura.

### Máquinas Virtuais

| Nome da VM | Sistema Operacional | Recursos Alocados | Serviços |
|---|---|---|---|
| VM-DC01 | Windows Server 2022 Datacenter | 4 vCPUs / 16 GB RAM / 150 GB | Active Directory, DNS, DHCP e GPO |
| VM-SEC01 | Windows Server 2022 Datacenter | 16 vCPUs / 64 GB RAM / 2 TB | Controle de acesso, VMS e banco de dados |
| VM-NAS01 | Ubuntu Server 22.04 LTS | 8 vCPUs / 32 GB RAM / 2,5 TB | Samba File Server e armazenamento |

### VM-DC01 — Active Directory

A VM-DC01 é responsável pelo gerenciamento centralizado dos usuários e computadores da empresa.

Os principais serviços são:

- Active Directory Domain Services (AD DS);
- DNS;
- DHCP;
- Gerenciamento de usuários;
- Grupos de segurança;
- Políticas de Grupo (GPO).

O domínio utilizado pela empresa é:

**fhenterprise.sec.br**

### VM-SEC01 — Segurança e Aplicações

A VM-SEC01 concentra os principais serviços relacionados à operação de segurança eletrônica da empresa.

Entre eles estão:

- Sistema de controle de acesso;
- Licenciamento do VMS;
- Banco de dados dos eventos de segurança;
- Serviços relacionados ao monitoramento;
- Integração com os sistemas de segurança.

### VM-NAS01 — Servidor de Arquivos

A VM-NAS01 utiliza Ubuntu Server e Samba para disponibilizar arquivos aos departamentos da empresa.

Entre os arquivos armazenados estão:

- Projetos CAD;
- Plantas baixas;
- Documentação técnica;
- Firmwares;
- Manuais operacionais;
- Arquivos administrativos.

---

## 3.2 Gerenciamento de Acessos e Diretivas de Segurança

O Active Directory é utilizado para centralizar a autenticação e o controle de acesso dos funcionários.

Os usuários são organizados em Unidades Organizacionais (OUs), de acordo com seus departamentos e funções.

### Política de Senhas

A política de segurança estabelece:

- Senhas com no mínimo 12 caracteres;
- Uso de letras maiúsculas e minúsculas;
- Utilização de números e caracteres especiais;
- Alteração periódica das credenciais;
- Bloqueio da conta após 5 tentativas malsucedidas.

### Segurança dos Computadores

Nas estações utilizadas pela Central de Monitoramento são aplicadas políticas para reduzir riscos de segurança e vazamento de informações.

Entre as medidas estão:

- Restrição de dispositivos USB de armazenamento;
- Controle de instalação de softwares;
- Aplicação de atualizações de segurança;
- Controle de acesso aos compartilhamentos;
- Utilização de contas individuais.

### Compartilhamentos de Rede

O acesso aos arquivos é realizado de acordo com a função do funcionário.

Exemplos:

`Z:\Projetos_Engenharia`

`Y:\Relatorios_CML`

Dessa forma, cada usuário recebe apenas os recursos necessários para desempenhar suas atividades.

---

## 3.3 Estratégia de Backup e Licenciamento

A FH Enterprise utiliza a estratégia de backup **3-2-1**.

### Regra 3-2-1

A estratégia consiste em:

**3 cópias dos dados:** uma cópia principal e duas cópias de backup.

**2 meios de armazenamento diferentes:** armazenamento local e armazenamento em nuvem.

**1 cópia fora do ambiente principal:** uma cópia armazenada externamente à Matriz.

Os backups incluem:

- Bancos de dados;
- Configurações dos servidores;
- Configurações do VMS;
- Informações do sistema de controle de acesso;
- Arquivos importantes da empresa.

A solução de backup utiliza o Veeam Backup & Replication, com armazenamento externo em serviço de nuvem.

### Licenciamento

Os servidores Windows utilizam licenciamento adequado ao ambiente corporativo, juntamente com as CALs necessárias.

As estações de trabalho utilizam Windows 11 Pro, enquanto o servidor de arquivos utiliza Ubuntu Server.

---

## 3.4 Segurança e Disponibilidade

A virtualização permite separar os serviços em diferentes máquinas virtuais. Dessa forma, os serviços podem ser administrados de maneira independente.

A infraestrutura também utiliza:

- RAID;
- Nobreak;
- Backup local;
- Backup externo;
- Active Directory;
- Políticas de segurança;
- Monitoramento da infraestrutura.

Essas tecnologias contribuem para a segurança, organização e disponibilidade dos serviços de TI da FH Enterprise.
