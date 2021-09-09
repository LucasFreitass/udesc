# ESSE ARQUIVO, É UM CODIGO " SCRIPT " EM R QUE GERA OS GRÁFICOS UTILIZADOS COMO RESULTADOS DO TRABALHO. 
# Toda a finalidade dele é apenas gerar o gráfico 

packages <- c("ggplot2","dplyr","scales","ggsci","rjson", "gridExtra")

for(package in packages){
    if(!require(package, character.only = TRUE)){
        install.packages(package, dep=TRUE)
        if(!require(package, character.only=TRUE)) stop("Pacote indisponivel")
        
    }
    library(package, character.only=TRUE)
}
rm(packages)
rm(package)

library(dplyr)

pallet_colors <- c("#00AFBB", "#E7B800", "#FC4E07","#52854C","#FFDB6D","#4E84C4")

valores<- read.table("logs.tempos",header=TRUE,sep=";", stringsAsFactors = FALSE)
valores$Tempo <- valores$Tempo / 10;

tiff("operacoes.tiff", width= 3600, height= 2200, units="px", res=400,compression = 'lzw')
p1 <- ggplot(data=valores, aes(x=Bits, y=Tempo, color = Funcao ))+
    #geom_point()+
    geom_line()+
    theme_classic()+
    theme(
        legend.position="top",
        axis.text.x = element_text(
            angle = 0,
            hjust = 0.7,
            size=10
        ),
        panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(),
        panel.background = element_blank(),
        axis.line = element_line(color = "black"),
        axis.text.y = element_text(size=12),
        axis.title.x = element_text(size=12),
        axis.title.y = element_text(size=12),
        legend.text = element_text(size=12),
        legend.title = element_text(size=12),
        legend.key = element_blank(),
        legend.box = "vertical"
    )+
    labs(
        x="Quantidade de Bits",
        y="Tempo (ms)",
        color= "Função"
    )+
    scale_y_continuous(limits=c(0,800), breaks=seq(0.0,800,50))+
    scale_x_continuous(
        breaks=seq(0,2000,100))+
    scale_color_discrete(
        limits=c("criptografar","descriptografar","geraChaves"),
        labels=c("Criptografar","Descriptografar", "Gerar Chaves PQ")
    )

plot(p1)
dev.off()
rm(p1)


valores<- read.table("logs_bruteforce.tempos",header=TRUE,sep=";", stringsAsFactors = FALSE)
valores$Tempo <- valores$Tempo / 1000;

tiff("fatoracao.tiff", width= 3600, height= 2200, units="px", res=400,compression = 'lzw')
p2 <- ggplot(data=valores, aes(x=Bits, y=Tempo, color = Funcao ))+
    #geom_point()+
    geom_line()+
    theme_classic()+
    theme(
        legend.position="top",
        axis.text.x = element_text(
            angle = 0,
            hjust = 0.7,
            size=10
        ),
        panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(),
        panel.background = element_blank(),
        axis.line = element_line(color = "black"),
        axis.text.y = element_text(size=12),
        axis.title.x = element_text(size=12),
        axis.title.y = element_text(size=12),
        legend.text = element_text(size=12),
        legend.title = element_text(size=12),
        legend.key = element_blank(),
        legend.box = "vertical"
    )+
    labs(
        x="Quantidade de Bits",
        y="Tempo (s)",
        color= "Força Bruta"
    )+
     scale_y_continuous(limits=c(0,600), breaks=seq(0.0,800,50))+
     scale_x_continuous(
         breaks=seq(0,120,10))+
     scale_color_discrete(
         limits=c("bruteForce","bruteForceHeuristica"),
         labels=c("Ingênuo","Pollard's Rho")
     )

plot(p2)
dev.off()
rm(p2)

system("for f in *.tiff; do convert -trim $f ${f%.*}.png; done;")
system("rm *.tiff")
