# Projeto de Infraestrutura — FH Enterprise

## Resumo
Planejamento de infraestrutura computacional para a FH Enterprise, empresa especializada em engenharia de segurança eletrônica, controle de acesso e CFTV IP. O projeto contempla Matriz e duas filiais (60 funcionários) com integração completa de hardware, virtualização, redes seguras, armazenamento redundante e monitoramento ambiental via IoT.

## Organização

* `01-Empresa/` : empresa, organograma e tabela-mestra de postos/funcionários.
* `02-Arquitetura/` : computadores, perfil especializado de monitoramento, servidor Dell, RAID 10, nobreak e orçamento.
* `03-Sistemas-Operacionais/` : Proxmox VE, VMs Windows Server/Ubuntu, diretivas de grupo (GPO), matriz de permissões e backup 3-2-1.
* `04-Redes/` : plantas baixas, topologia lógica/física, sub-redes VLSM, VLANs para dados/CFTV, Wi-Fi e inventário de equipamentos.
* `05-IoT/` : código fonte Arduino C++, circuito de monitoramento do Datacenter e relatórios dos 3 cenários de teste.
* `07-Referencias/` : normas consultadas e fontes de pesquisa.

## Como consultar
Comece abrindo a pasta `01-Empresa/` para entender o perfil da organização e siga sequencialmente até a pasta `05-IoT/`. Em cada pasta, consulte o arquivo Markdown de explicação principal ou as planilhas complementares.

## Links técnicos
* Tinkercad: https://encurtador.com.br/lhCj
* Repositório Oficial: https://github.com/fhfds1930/fhenterprise-infraestrutura/tree/main

## Ferramentas
Excel / Google Planilhas, Word / Google Docs, Draw.io, Cisco Packet Tracer, Tinkercad e GitHub.

**Última atualização:** 13/09/2026
