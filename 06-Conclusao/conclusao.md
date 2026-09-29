# 06 - Conclusão

O projeto apresentou uma proposta completa de infraestrutura computacional para a FH Enterprise, empresa fictícia especializada em controle de acesso, segurança eletrônica e monitoramento por CFTV IP.

A arquitetura desenvolvida contempla servidores de alto desempenho, virtualização, armazenamento redundante, estações de trabalho adequadas às diferentes funções da empresa e mecanismos de proteção elétrica. A utilização do Proxmox VE permite concentrar diferentes serviços em máquinas virtuais, facilitando o gerenciamento da infraestrutura.

Na área de sistemas operacionais, foram definidos servidores Windows Server e Linux, com Active Directory, DNS, DHCP, compartilhamento de arquivos e serviços relacionados à operação de segurança. A estratégia de backup baseada no conceito 3-2-1 também contribui para a proteção dos dados corporativos e para a continuidade dos serviços.

A infraestrutura de redes foi organizada utilizando VLANs, endereçamento IP privado, firewall, Wi-Fi corporativo e VPN IPsec entre a Matriz e as filiais. Essa arquitetura possibilita separar o tráfego administrativo do tráfego gerado pelos dispositivos de CFTV e controle de acesso.

A aplicação de Internet das Coisas complementa a solução por meio de um sistema de monitoramento ambiental do datacenter. O circuito desenvolvido com Arduino, sensor TMP36, display LCD, LEDs, buzzer e servo permite identificar diferentes níveis de temperatura e gerar alertas conforme a condição detectada.

Portanto, a solução proposta integra arquitetura de computadores, sistemas operacionais, redes de computadores e Internet das Coisas em uma única infraestrutura, considerando os requisitos de segurança, disponibilidade, organização e possibilidade de expansão da FH Enterprise.
