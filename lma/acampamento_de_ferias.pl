% RESOLUÇÃO EXERCÍCIO ACAMPAMENTO DE FÉRIAS:
% https://rachacuca.com.br/logica/problemas/acampamento-de-ferias/
% FEITO POR: Lucas Eduardo Rosa de Freitas.
% CODIGO FEITO EM PROLOG.


go:-statistics(cputime,T1),
    modelo([A1, A2, A3, A4, A5]),
    	    writeln("\n A1":A1),
            writeln("\n A2":A2),
            writeln("\n A3":A3),
            writeln("\n A4":A4),
            writeln("\n A5":A5),
            statistics(cputime ,T2),
            Tempo_BUSCA is T2 - T1,
    format('\n T1: ~f \t T2: ~f  msec', [T1, T2]),
    format('\n Tempo total: ~10f  msec', Tempo_BUSCA).


modelo([(Barraca_1,Nome_1,Idade_1,Sanduiche_1,Equipe_1,Esporte_1),
          (Barraca_2,Nome_2,Idade_2,Sanduiche_2,Equipe_2,Esporte_2),
          (Barraca_3,Nome_3,Idade_3,Sanduiche_3,Equipe_3,Esporte_3),
          (Barraca_4,Nome_4,Idade_4,Sanduiche_4,Equipe_4,Esporte_4),
          (Barraca_5,Nome_5,Idade_5,Sanduiche_5,Equipe_5,Esporte_5)]) :-

%barracas
barracas(Barraca_1),
barracas(Barraca_2),
barracas(Barraca_3),
barracas(Barraca_4),
barracas(Barraca_5),

alldifferent([Barraca_1,Barraca_2,Barraca_3,Barraca_4,Barraca_5]),

%NOME
nomes(Nome_1),
nomes(Nome_2),
nomes(Nome_3),
nomes(Nome_4),
nomes(Nome_5),

%Breno está em algum lugar à direita da barraca Vermelha.
(
(Barraca_1==vermelha, (Nome_2==breno; Nome_3==breno; Nome_4==breno; Nome_5==breno));
(Barraca_2==vermelha, (Nome_3==breno; Nome_4==breno; Nome_5==breno));
(Barraca_3==vermelha, (Nome_4==breno; Nome_5==breno));
(Barraca_4==vermelha, Nome_5==breno)
),

alldifferent([Nome_1,Nome_2,Nome_3,Nome_4,Nome_5]),


%IDADE
idades(Idade_1),
idades(Idade_2),
idades(Idade_3),
idades(Idade_4),
idades(Idade_5),

%O menino de 10 anos está em algum lugar à direita da barraca Vermelha.
(
(Barraca_1==vermelha, (Idade_2==10; Idade_3==10; Idade_4==10; Idade_5==10));
(Barraca_2==vermelha, (Idade_3==10; Idade_4==10; Idade_5==10));
(Barraca_3==vermelha, (Idade_4==10; Idade_5==10));
(Barraca_4==vermelha, Idade_5==10)
),


%O menino de 9 anos está em algum lugar à direita da barraca Verde.
(
(Barraca_1==verde, (Idade_2==9; Idade_3==9; Idade_4==9; Idade_5==9));
(Barraca_2==verde, (Idade_3==9; Idade_4==9; Idade_5==9));
(Barraca_3==verde, (Idade_4==9; Idade_5==9));
(Barraca_4==verde, Idade_5==9)
),

%A barraca Amarela está em algum lugar à esquerda do garoto de 12 anos.
(
(Idade_5==12, (Barraca_1==amarela; Barraca_2==amarela; Barraca_3==amarela; Barraca_4==amarela));
(Idade_4==12, (Barraca_1==amarela; Barraca_2==amarela; Barraca_3==amarela));
(Idade_3==12, (Barraca_1==amarela; Barraca_2==amarela));
(Idade_2==12, Barraca_1==amarela)
),

alldifferent([Idade_1,Idade_2,Idade_3,Idade_4,Idade_5]),

%SANDUICHE
sanduiches(Sanduiche_1),
sanduiches(Sanduiche_2),
sanduiches(Sanduiche_3),
sanduiches(Sanduiche_4),
sanduiches(Sanduiche_5),

%O garoto da barraca Verde gosta de sanduíche de Atum.
(
(Barraca_1==verde,Sanduiche_1==atum);
(Barraca_2==verde,Sanduiche_2==atum);
(Barraca_3==verde,Sanduiche_3==atum);
(Barraca_4==verde,Sanduiche_4==atum);
(Barraca_5==verde,Sanduiche_5==atum)
),
(
(Barraca_2==vermelho , ((Sanduiche_1==presunto , Idade_3==12) ; (Sanduiche_3==presunto , Idade_1==12)));
(Barraca_3==vermelho , ((Sanduiche_2==presunto , Idade_4==12) ; (Sanduiche_4==presunto , Idade_2==12)));
(Barraca_4==vermelho , ((Sanduiche_3==presunto , Idade_5==12) ; (Sanduiche_5==presunto , Idade_3==12)))
),

%Gabriel está ao lado do menino que gosta de sanduíche de Frango.
(
(Sanduiche_1==frango,Nome_2==gabriel);
(Sanduiche_2==frango,(Nome_1==gabriel;Nome_3==gabriel));
(Sanduiche_3==frango,(Nome_2==gabriel;Nome_4==gabriel));
(Sanduiche_4==frango,(Nome_3==gabriel;Nome_5==gabriel));
(Sanduiche_5==frango,Nome_4==gabriel)
),

%O menino que gosta de sanduíche de Salame está ao lado de quem está na barraca Verde.
(
(Barraca_1==verde,Sanduiche_2==salame);
(Barraca_2==verde,(Sanduiche_1==salame;Sanduiche_3==salame));
(Barraca_3==verde,(Sanduiche_2==salame;Sanduiche_4==salame));
(Barraca_4==verde,(Sanduiche_3==salame;Sanduiche_5==salame));
(Barraca_5==verde,Sanduiche_4==salame)
),

%Quem gosta de sanduíche de Frago está em algum lugar à direita da barraca Verde.
(
(Barraca_1==verde,(Sanduiche_2==frango; Sanduiche_3==frango; Sanduiche_4==frango; Sanduiche_5==frango));
(Barraca_2==verde,(Sanduiche_3==frango; Sanduiche_4==frango; Sanduiche_5==frango));
(Barraca_3==verde,(Sanduiche_4==frango; Sanduiche_5==frango));
(Barraca_4==verde,Sanduiche_5==frango)
),


alldifferent([Sanduiche_1,Sanduiche_2,Sanduiche_3,Sanduiche_4,Sanduiche_5]),


%EQUIPE
equipes(Equipe_1),
equipes(Equipe_2),
equipes(Equipe_3),
equipes(Equipe_4),
equipes(Equipe_5),

%O garoto da equipe Tupis está em uma das pontas.
(Equipe_5==tupis),

%O garoto da equipe Rocket está exatamente à esquerda de Rui.
(
(Equipe_1==rocket,Nome_2==rui);
(Equipe_2==rocket,Nome_3==rui);
(Equipe_3==rocket,Nome_4==rui);
(Equipe_4==rocket,Nome_5==rui)
),

alldifferent([Equipe_1,Equipe_2,Equipe_3,Equipe_4,Equipe_5]),

%ESPORTE
esportes(Esporte_1),
esportes(Esporte_2),
esportes(Esporte_3),
esportes(Esporte_4),
esportes(Esporte_5),

%Na primeira barraca está o garoto que gosta de Natação.
Esporte_1==natacao,
% **
(
(Esporte_5==futebol , Equipe_4==rocket);
(Esporte_4==futebol , Equipe_3==rocket);
(Esporte_3==futebol , Equipe_2==rocket);
(Esporte_2==futebol , Equipe_1==rocket)
),

% **
(
(Barraca_5==verde , Esporte_4==tenis);
(Barraca_4==verde , Esporte_3==tenis);
(Barraca_3==verde , Esporte_2==tenis);
(Barraca_2==verde , Esporte_1==tenis)
),

%O menino que gosta de Futebol está ao lado do menino da equipe Ciclanos.
(
(Esporte_2==futebol,(Equipe_1==ciclanos;Equipe_3==ciclanos));
(Esporte_3==futebol,(Equipe_2==ciclanos;Equipe_4==ciclanos));
(Esporte_4==futebol,(Equipe_3==ciclanos;Equipe_5==ciclanos));
(Esporte_5==futebol,Equipe_4==ciclanos)
),

%A barraca Vermelha está em algum lugar entre o garoto mais velho e quem gosta de Basquete, nessa ordem.
(
(Idade_1==13,Esporte_3==basquete,(Barraca_2==vermelha));
(Idade_1==13,Esporte_4==basquete,(Barraca_2==vermelha;Barraca_3==vermelha));
(Idade_1==13,Esporte_5==basquete,(Barraca_2==vermelha;Barraca_3==vermelha;Barraca_4==vermelha));
(Idade_2==13,Esporte_4==basquete,(Barraca_3==vermelha));
(Idade_2==13,Esporte_5==basquete,(Barraca_3==vermelha;Barraca_4==vermelha));
(Idade_3==13,Esporte_5==basquete,(Barraca_4==vermelha))
),

%O menino da equipe Dragão está ao lado de quem gosta de jogar Tênis.
(
(Esporte_1==tenis,Equipe_2==dragao);
(Esporte_2==tenis,Equipe_1==dragao);
(Esporte_2==tenis,Equipe_3==dragao);
(Esporte_3==tenis,Equipe_2==dragao);
(Esporte_3==tenis,Equipe_4==dragao);
(Esporte_4==tenis,Equipe_3==dragao);
(Esporte_4==tenis,Equipe_5==dragao);
(Esporte_5==tenis,Equipe_4==dragao)
),

%Quem gosta de Corrida está em algum lugar à direita da barraca Verde.
(
(Barraca_1==verde,(Esporte_2==corrida; Esporte_3==corrida; Esporte_4==corrida; Esporte_5==corrida));
(Barraca_2==verde,(Esporte_3==corrida; Esporte_4==corrida; Esporte_5==corrida));
(Barraca_3==verde,(Esporte_4==corrida; Esporte_5==corrida));
(Barraca_4==verde,Esporte_5==corrida)
),


%A barraca Vermelha está em algum lugar à esquerda de quem gosta de Basquete.
(
(Esporte_5==basquete,(Barraca_1==vermelha; Barraca_2==vermelha; Barraca_3==vermelha; Barraca_4==vermelha));
(Esporte_4==basquete,(Barraca_1==vermelha; Barraca_2==vermelha; Barraca_3==vermelha));
(Esporte_3==basquete,(Barraca_1==vermelha; Barraca_2==vermelha));
(Esporte_2==basquete,Barraca_1==vermelha)
),

alldifferent([Esporte_1,Esporte_2,Esporte_3,Esporte_4,Esporte_5]),






%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%BASE%
barracas(amarela).
barracas(azul).
barracas(branca).
barracas(verde).
barracas(vermelha).

nomes(anderson).
nomes(breno).
nomes(gabriel).
nomes(marco).
nomes(rui).

idades(9).
idades(10).
idades(11).
idades(12).
idades(13).

sanduiches(atum).
sanduiches(frango).
sanduiches(presunto).
sanduiches(queijo).
sanduiches(salame).

equipes(alfafas).
equipes(ciclanos).
equipes(dragao).
equipes(rocket).
equipes(tupis).

esportes(basquete).
esportes(corrida).
esportes(futebol).
esportes(natacao).
esportes(tenis).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
alldifferent([]).
alldifferent([H|T]):- not(member(H,T)),
alldifferent(T).
