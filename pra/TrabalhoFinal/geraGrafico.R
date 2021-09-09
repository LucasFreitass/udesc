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

names(df) <- c("Teste", "Tamanho Arvore","Operações")

pdf("resultadosCasos.pdf",width= 9, height= 4)
ggplot(data=df, aes(x=df$"Tamanho Arvore", y=df$"Operações", color=df$"Teste"))+
  geom_line() +
  theme_classic()
dev.off() 