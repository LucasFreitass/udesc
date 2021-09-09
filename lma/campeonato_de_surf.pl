% RESOLUÇÃO EXERCÍCIO CAMPEONATO DE SURF:
% https://rachacuca.com.br/logica/problemas/campeonato-de-surf/
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

modelo( [ (Cor_1,Nome_1,Praia_1,Tamanho_1,Gentilico_1,Ranking_1),
          (Cor_2,Nome_2,Praia_2,Tamanho_2,Gentilico_2,Ranking_2),
          (Cor_3,Nome_3,Praia_3,Tamanho_3,Gentilico_3,Ranking_3),
          (Cor_4,Nome_4,Praia_4,Tamanho_4,Gentilico_4,Ranking_4),
          (Cor_5,Nome_5,Praia_5,Tamanho_5,Gentilico_5,Ranking_5)
        ]) :-

 %Ranks
    ranks(Ranking_1),
    ranks(Ranking_2),
    ranks(Ranking_3),
    ranks(Ranking_4),
    ranks(Ranking_5),

    % O surfista que está no 5 lugar do Ranking está na quarta posição.
    Ranking_4==5,



  alldifferent([Ranking_1,Ranking_2,Ranking_3,Ranking_4,Ranking_5]),

  % O 8 do Ranking está exatamente à esquerda do 5 lugar.

  (Ranking_3==8),

  %cor
      cores(Cor_1),
      cores(Cor_2),
      cores(Cor_3),
      cores(Cor_4),
      cores(Cor_5),

      %O Primeiro do ranking está em algum lugar à direita do surfista da prancha Amarelo.

          (
      	(Cor_1==amarelo,Ranking_2==1);
      	(Cor_1==amarelo,Ranking_3==1);
      	(Cor_1==amarelo,Ranking_4==1);
      	(Cor_1==amarelo,Ranking_5==1);

      	(Cor_2==amarelo,Ranking_3==1);
      	(Cor_2==amarelo,Ranking_4==1);
      	(Cor_2==amarelo,Ranking_5==1);

      	(Cor_3==amarelo,Ranking_4==1);
      	(Cor_3==amarelo,Ranking_5==1);

      	(Cor_4==amarelo,Ranking_5==1)

      	),
      alldifferent([Cor_1,Cor_2,Cor_3,Cor_4,Cor_5]),



  %Gentilico
      gentilicos(Gentilico_1),
      gentilicos(Gentilico_2),
      gentilicos(Gentilico_3),
      gentilicos(Gentilico_4),
      gentilicos(Gentilico_5),

      % O dono da prancha Azul está em algum lugar à esquerda do Paulista.
      (
      (Gentilico_5==paulista,(Cor_1==azul; Cor_2==azul; Cor_3==azul; Cor_4==azul));
      (Gentilico_4==paulista,(Cor_1==azul; Cor_2==azul; Cor_3==azul));
      (Gentilico_3==paulista,(Cor_1==azul; Cor_2==azul));
      (Gentilico_2==paulista,Cor_1==azul)
      ),

 alldifferent([Gentilico_1,Gentilico_2,Gentilico_3,Gentilico_4,Gentilico_5]),

 % O Gaúcho está em algum lugar à direita do surfista da prancha Verde.
 (
 (Cor_1==verde,(Gentilico_2==gaucho; Gentilico_3==gaucho; Gentilico_4==gaucho; Gentilico_5==gaucho));
 (Cor_2==verde,(Gentilico_3==gaucho; Gentilico_4==gaucho; Gentilico_5==gaucho));
 (Cor_3==verde,(Gentilico_4==gaucho; Gentilico_5==gaucho));
 (Cor_4==verde,Gentilico_5==gaucho)
 ),

 %%O Mineiro está ao lado do Oitavo do ranking.
 (
 (Ranking_1==8,Gentilico_2==mineiro);
 (Ranking_2==8,Gentilico_1==mineiro);
 (Ranking_2==8,Gentilico_3==mineiro);
 (Ranking_3==8,Gentilico_2==mineiro);
 (Ranking_3==8,Gentilico_4==mineiro);
 (Ranking_4==8,Gentilico_3==mineiro);
 (Ranking_4==8,Gentilico_5==mineiro);
 (Ranking_5==8,Gentilico_4==mineiro)
),

% O Baiano está exatamente à direita do Mineiro.
(
(Gentilico_1==mineiro,Gentilico_2==baiano);
(Gentilico_2==mineiro,Gentilico_3==baiano);
(Gentilico_3==mineiro,Gentilico_4==baiano);
(Gentilico_4==mineiro,Gentilico_5==baiano)
),

     %tamanho

     tamanhos(Tamanho_1),
     tamanhos(Tamanho_2),
     tamanhos(Tamanho_3),
     tamanhos(Tamanho_4),
     tamanhos(Tamanho_5),

     % O surfita da prancha de 6'0" está na quinta posição.
     Tamanho_5==60,

     alldifferent([Tamanho_1,Tamanho_2,Tamanho_3,Tamanho_4,Tamanho_5]),



%NOME
    nomes(Nome_1),
    nomes(Nome_2),
    nomes(Nome_3),
    nomes(Nome_4),
    nomes(Nome_5),

    %  O dono da prancha de 5'8" está em algum lugar entre o Tomas e o dono da prancha de 5'7", nessa ordem.
    (
    (Nome_1==tomas,Tamanho_3==57,(Tamanho_2==58));
    (Nome_1==tomas,Tamanho_4==57,(Tamanho_2==58;Tamanho_3==58));
    (Nome_1==tomas,Tamanho_5==57,(Tamanho_2==58;Tamanho_3==58;Tamanho_4==58));
    (Nome_2==tomas,Tamanho_4==57,(Tamanho_3==58));
    (Nome_2==tomas,Tamanho_5==57,(Tamanho_3==58;Tamanho_4==58));
    (Nome_3==tomas,Tamanho_5==57,(Tamanho_4==58))
    ),

    alldifferent([Nome_1,Nome_2,Nome_3,Nome_4,Nome_5]),

    % O surfita da prancha de 5'11" está em algum lugar entre o 2 do Ranking e o surfista da prancha de 5'8", nessa ordem.
    (
    (Ranking_1==2,Tamanho_3==58,(Tamanho_2==511));
    (Ranking_1==2,Tamanho_4==58,(Tamanho_2==511;Tamanho_3==511));
    (Ranking_1==2,Tamanho_5==58,(Tamanho_2==511;Tamanho_3==511;Tamanho_4==511));
    (Ranking_2==2,Tamanho_4==58,(Tamanho_3==511));
    (Ranking_2==2,Tamanho_5==58,(Tamanho_3==511;Tamanho_4==511));
    (Ranking_3==2,Tamanho_5==58,(Tamanho_4==511))
    ),

    %praias
        praias(Praia_1),
        praias(Praia_2),
        praias(Praia_3),
        praias(Praia_4),
        praias(Praia_5),

        %  O surfista que curte surfar em Maresias está exatamente à direita do surfista da prancha de 5'7".
        (
        (Tamanho_1==57,Praia_2==maresias);
        (Tamanho_2==57,Praia_3==maresias);
        (Tamanho_3==57,Praia_4==maresias);
        (Tamanho_4==57,Praia_5==maresias)
        ),

        alldifferent([Praia_1,Praia_2,Praia_3,Praia_4,Praia_5]),

        %  O dono da prancha Amarela está ao lado do surfista que gosta de surfar em Areado.
        (
        (Cor_1==amarelo, Praia_2==areado);
        (Cor_2==amarelo, (Praia_1==areado; Praia_3==areado));
        (Cor_3==amarelo, (Praia_2==areado; Praia_4==areado));
        (Cor_4==amarelo, (Praia_3==areado; Praia_5==areado));
        (Cor_5==amarelo, Praia_4==areado)
        ),

        %  Quem gosta de surfar em Itamambuca está exatamente à esquerda de quem gosta de surfar em Areado.
        (
        (Praia_1==itamambuca,Praia_2==areado);
        (Praia_2==itamambuca,Praia_3==areado);
        (Praia_3==itamambuca,Praia_4==areado);
        (Praia_4==itamambuca,Praia_5==areado)
        ),

        % O surfista da prancha Amarela está em algum lugar entre o que curte surfar em Brava e o 5 do Ranking, nessa ordem.
        (
        (Praia_1==brava,Ranking_3==5,(Cor_2==amarelo));
        (Praia_1==brava,Ranking_4==5,(Cor_2==amarelo;Cor_3==amarelo));
        (Praia_1==brava,Ranking_5==5,(Cor_2==amarelo;Cor_3==amarelo;Cor_4==amarelo));
        (Praia_2==brava,Ranking_4==5,(Cor_3==amarelo));
        (Praia_2==brava,Ranking_5==5,(Cor_3==amarelo;Cor_4==amarelo));
        (Praia_3==brava,Ranking_5==5,(Cor_4==amarelo))
        ),

        % Igor está em algum lugar à direita do dono da prancha Verde.
        (
        (Cor_1==verde,(Nome_2==igor; Nome_3==igor; Nome_4==igor; Nome_5==igor));
        (Cor_2==verde,(Nome_3==igor; Nome_4==igor; Nome_5==igor));
        (Cor_3==verde,(Nome_4==igor; Nome_5==igor));
        (Cor_4==verde, Nome_5==igor)
        ),

        % O surfista da pranhca Amarela está em algum lugar à esquerda do Flávio.
        (
        (Nome_5==flavio,(Cor_1==amarelo; Cor_2==amarelo; Cor_3==amarelo; Cor_4==amarelo));
        (Nome_4==flavio,(Cor_1==amarelo; Cor_2==amarelo; Cor_3==amarelo));
        (Nome_3==flavio,(Cor_1==amarelo; Cor_2==amarelo));
        (Nome_2==flavio,Cor_1==amarelo)
        ),

        % Fernando está em algum lugar entre o dono da prancha Vermelha e o Rogério, nessa ordem.
        (
        (Cor_1==vermelho,Nome_3==rogerio,(Nome_2==fernando));
        (Cor_1==vermelho,Nome_4==rogerio,(Nome_2==fernando;Nome_3==fernando));
        (Cor_1==vermelho,Nome_5==rogerio,(Nome_2==fernando;Nome_3==fernando;Nome_4==fernando));
        (Cor_2==vermelho,Nome_4==rogerio,(Nome_3==fernando));
        (Cor_2==vermelho,Nome_5==rogerio,(Nome_3==fernando;Nome_4==fernando));
        (Cor_3==vermelho,Nome_5==rogerio,(Nome_4==fernando))
        ),

        % O Gaúcho está na Quarta posição.
        Gentilico_4==gaucho,

        % O dono da prancha Amarela está em algum lugar entre o surfista da prancha Vermelha e o que curte surfar em Itaguaré, nessa ordem.
        (
        (Cor_1==vermelho,Praia_3==itaguare,(Cor_2==amarelo));
        (Cor_1==vermelho,Praia_4==itaguare,(Cor_2==amarelo;Cor_3==amarelo));
        (Cor_1==vermelho,Praia_5==itaguare,(Cor_2==amarelo;Cor_3==amarelo;Cor_4==amarelo));
        (Cor_2==vermelho,Praia_4==itaguare,(Cor_3==amarelo));
        (Cor_2==vermelho,Praia_5==itaguare,(Cor_3==amarelo;Cor_4==amarelo));
        (Cor_3==vermelho,Praia_5==itaguare,(Cor_4==amarelo))
        ),


%FIM DO MODELO
nl,
write('FIM DO MODELO').
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%BASE%
cores(amarelo).
cores(azul).
cores(branco).
cores(verde).
cores(vermelho).

nomes(flavio).
nomes(fernando).
nomes(igor).
nomes(rogerio).
nomes(tomas).

praias(areado).
praias(brava).
praias(itaguare).
praias(itamambuca).
praias(maresias).

tamanhos(56).
tamanhos(57).
tamanhos(58).
tamanhos(511).
tamanhos(60).

gentilicos(gaucho).
gentilicos(baiano).
gentilicos(fluminense).
gentilicos(mineiro).
gentilicos(paulista).

ranks(1).
ranks(2).
ranks(3).
ranks(5).
ranks(8).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
alldifferent([]).
alldifferent([H|T]):- not(member(H,T)),
alldifferent(T).
