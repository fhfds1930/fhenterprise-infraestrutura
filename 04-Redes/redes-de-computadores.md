# 04 - Redes de Computadores

## 4.1 Topologia de Rede e Diagrama Lógico

A infraestrutura de rede da FH Enterprise foi projetada para conectar a Matriz, localizada em São Paulo, às duas filiais, localizadas em Campinas e Santos. A comunicação entre as unidades utiliza túneis VPN Site-to-Site com IPsec, proporcionando criptografia para o tráfego corporativo.

A topologia física adotada é do tipo Estrela Estendida. Na Matriz, um switch central concentra as conexões dos servidores, estações de trabalho, dispositivos de segurança eletrônica e demais equipamentos de rede.

### Diagrama lógico

```text
                              INTERNET
                                  |
                           +--------------+
                           |   FIREWALL   |
                           +------+-------+
                                  |
                         +--------+--------+
                         | ROTEADOR MATRIZ |
                         | Cisco ISR 4331  |
                         +--------+--------+
                                  |
                         +--------+--------+
                         |   CORE SWITCH   |
                         |   Cisco PoE+    |
                         +--------+--------+
                                  |
             +--------------------+--------------------+
             |                    |                    |
          VLAN 10              VLAN 20              VLAN 30
        Gestão/TI            Corporativo              CFTV
             |                    |                    |
       PCs de TI              AD/DHCP          Câmeras IP
       NOC e gestão           Servidores        Catracas
                                                  Biometria

                                  |
                         ===== VPN IPsec =====
                           /               \
                          /                 \
              +---------+---------+   +-----+-------------+
              | ROTEADOR CAMPINAS |   | ROTEADOR SANTOS  |
              | Cisco ISR 4331    |   | Cisco ISR 4331   |
              +---------+---------+   +---------+---------+
                        |                       |
                    VLAN 100                VLAN 200
                        |                       |
                 Vendas/Campo              CML 24/7
                  Laboratório              Monitoramento

4.2 Endereçamento IP e VLANs

A rede utiliza endereçamento privado baseado na faixa 10.0.0.0/8. A segmentação por VLAN permite separar diferentes tipos de tráfego e facilitar a aplicação de políticas de segurança.

Localidade	VLAN	Nome	Sub-rede	Gateway

Matriz	10	Gestão e TI	10.10.10.0/24	10.10.10.1
Matriz	20	Corporativo / AD	10.10.20.0/24	10.10.20.1
Matriz	30	CFTV e Controle de Acesso	10.10.30.0/24	10.10.30.1
Campinas	100	Vendas e Laboratório Técnico	10.20.10.0/24	10.20.10.1
Santos	200	Central de Monitoramento	10.30.10.0/24	10.30.10.1
Todas	999	Visitantes	172.16.0.0/23	Conforme firewall


A VLAN 30 é destinada aos dispositivos de segurança eletrônica, como câmeras IP, catracas, leitores biométricos e controladores de acesso.

A VLAN 999 é destinada aos visitantes e possui isolamento dos recursos internos da empresa, permitindo somente acesso à Internet.

4.3 Comunicação entre as Filiais

A comunicação entre a Matriz e as filiais ocorre através de VPN Site-to-Site utilizando IPsec e criptografia AES-256.

Os enlaces são:

São Paulo ↔ Campinas

São Paulo ↔ Santos


Os roteadores Cisco ISR 4331 são responsáveis pelo estabelecimento dos túneis VPN. O protocolo OSPF é utilizado para gerenciamento dinâmico das rotas entre os locais.

4.4 Rede Wi-Fi

A infraestrutura Wi-Fi possui duas redes principais.

FH_SEC_CORP

Rede corporativa destinada aos funcionários. Utiliza WPA3-Enterprise e autenticação integrada ao Active Directory.

FH_VISITANTES

Rede destinada a visitantes. Utiliza a VLAN 999 e possui isolamento dos recursos internos da empresa.

4.5 Segurança da Rede

As principais medidas de segurança são:

VLANs separadas para diferentes funções;

Firewall na borda da rede;

VPN IPsec entre as unidades;

WPA3-Enterprise para Wi-Fi corporativo;

Rede de visitantes isolada;

Controle de acesso aos dispositivos de CFTV;

Active Directory para autenticação;

ACLs para controlar a comunicação entre segmentos;

Monitoramento dos equipamentos pelo setor de TI/NOC.


4.6 Justificativa da Arquitetura

A arquitetura proposta atende às necessidades da FH Enterprise porque separa os diferentes tipos de tráfego e permite comunicação segura entre as três unidades.

A utilização de VLANs reduz o domínio de broadcast e facilita a aplicação de políticas de segurança. A VPN IPsec protege a comunicação entre as unidades, enquanto os switches PoE+ permitem a alimentação de câmeras IP e dispositivos de controle de acesso através do cabeamento de rede.

Dessa forma, a infraestrutura oferece organização, segurança, escalabilidade e disponibilidade para os serviços de controle de acesso e monitoramento eletrônico da empresa.

