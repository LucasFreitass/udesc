create database avaliacaoODAW

use avaliacaoODAW

CREATE TABLE `avaliacaoodaw`.`usuario` (
  `usuario_id` INT NOT NULL AUTO_INCREMENT,
  `usuario` VARCHAR(200) NOT NULL,
  `senha` VARCHAR(32) NULL,
  PRIMARY KEY (`usuario_id`));


insert into usuario (usuario, senha) VALUES ('Lucas', md5('Senha')); 

insert into usuario (usuario, senha) VALUES ('Joao', md5('1234')); 

insert into usuario (usuario, senha) VALUES ('Marcos', md5('asdf')); 


select * from usuario


---------

CREATE TABLE `avaliacaoodaw`.`farmacia` (
  `id_paciente` INT NOT NULL AUTO_INCREMENT,
  `nome_pac` VARCHAR(200) NOT NULL,
  `email` VARCHAR(45) NULL,
   `genero` VARCHAR(45) NULL,
    `nome_reme` VARCHAR(45) NULL,
     `tarja` VARCHAR(45) NULL,
      `extras` VARCHAR(45) NULL,
  PRIMARY KEY (`usuario_id`));

select * from farmacia

insert into farmacia (nome_pac, email, genero, nome_reme, tarja, extras) VALUES ('Teste1', 'teste@gmail.com', 'Homem', 
'Remedio teste', 'Tarja preta', 'testando o campo de texto entra'); 