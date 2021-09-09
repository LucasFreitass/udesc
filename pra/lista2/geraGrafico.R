packages <- c("ggplot2")

for(package in packages){
    if(!require(package, character.only = TRUE)){
        install.packages(package, dep=TRUE)
        if(!require(package, character.only=TRUE)) stop("Pacote indisponivel")
        
    }
    library(package, character.only=TRUE)
}
rm(packages)
rm(package)

df <- read.table("saidasTrabFinal.txt", header=FALSE, sep=";")

names(df) <- c("Teste", "Tamanho Arvore","Adição","Balanceamento")

pdf("rdddesultados.pdf",width= 9, height= 4)
ggplot(data=df, aws(y="Tamanho Arvore"))+
  geom_line(aes(x=$)) 
#ggplot(data=df, aes(x=Tamanho, y=Iterações, group=Algoritmos)) +
#    geom_line(aes(linetype=Algoritmos, color=Algoritmos))+
#    theme_classic()
#dev.off() 