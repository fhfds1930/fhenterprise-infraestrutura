# 02 - Arquitetura de Computadores

## Servidor Central (Datacenter Matriz)
- **Modelo:** Dell PowerEdge R650 Server
- **Processador (CPU):** 2x Intel Xeon Silver 4314 (32 Cores / 64 Threads no total, 2.40GHz)
- **Memória RAM:** 128 GB DDR4 ECC Registered (4x 32GB) 3200MHz
- **Fonte de Alimentação:** Dupla Fonte Redundante (1+1) de 800W Hot-Plug
- **Placa de Rede:** Quad-Port 10GbE SFP+ / 1GbE RJ45


## Arranjo de Discos (RAID)

| Volume RAID | Tecnologia e Discos | Capacidade Útil | Finalidade e Justificativa Técnica |
| **RAID 1** | 2x SSD NVMe Enterprise 960GB Hot-Plug | 960 GB | Hospedagem do Hypervisor Proxmox VE e instâncias dos sistemas operacionais (baixa latência e alto desempenho). |
| **RAID 10** | 4x HDD SAS 2.4TB 10k RPM Enterprise | 4.8 TB | Armazenamento de banco de dados do controle de acesso, projetos CAD e buffer de imagens de CFTV (redundância + velocidade de escrita). |


## Estações de Trabalho
- **Modelo Padrão (45 unidades - ADM/Vendas/Campo):** Dell OptiPlex SFF 7010 (Intel i5-13500, 16GB RAM, SSD 512GB NVMe, Monitor 23.8" FHD).
- **Modelo Performance (15 unidades - Monitoramento 24/7 e Engenharia):** Dell Precision Tower 3660 (Intel i7-13700, 32GB RAM, SSD 1TB NVMe, GPU NVIDIA RTX 3060 12GB).


## Proteção Elétrica e Dimensionamento de Custos
- **Nobreak:** APC Smart-UPS RT 3000VA / 2700W 230V com módulo de expansão de bateria (Autonomia de até 45 minutos).

| Item de Hardware | Qtd. | Valor Unitário Estimado (R$) | Valor Total Estimado (R$) |
| Servidor Dell PowerEdge R650 (Datacenter) | 1 | R$ 48.000,00 | R$ 48.000,00 |
| Desktops Dell OptiPlex 7010 (ADM/Vendas) | 45 | R$ 4.200,00 | R$ 189.000,00 |
| Workstations Dell Precision + GPU (CML/Engenharia) | 15 | R$ 8.500,00 | R$ 127.500,00 |
| Nobreak APC Smart-UPS 3000VA On-Line | 1 | R$ 14.500,00 | R$ 14.500,00 |
| Switches Cisco Catalyst 2960-X (PoE+) | 4 | R$ 9.800,00 | R$ 39.200,00 |
| Roteadores Cisco ISR 4331/K9 (Borda/VPN) | 3 | R$ 11.000,00 | R$ 33.000,00 |
| **Custo Total de Hardware e Conectividade** | **-** | **-** | **R$ 451.200,00** |
