<?php 
session_start();
include('conex.php');

if (empty($_POST['usuario']) || empty($_POST['senha'])) {    // AQUI É FEITA UMA VALIDAÇÃO PARA NÃO PODER ACESSAR A OUTRA PÁGINA
    header('Location: index.php');                                      /// SEM COLOCAR O USUARIO OU A SENHA
    exit();
}

$usuario = mysqli_real_escape_string($conex, $_POST['usuario']);
$senha = mysqli_real_escape_string($conex, $_POST['senha']);

$query = "select usuario_id, usuario from usuario where usuario = '{$usuario}' and senha = md5('{$senha}')";
// NA LINHA ACIMA JÁ É FEITO A VALIDAÇÃO, PARA O USUÁRIO E A SENHA ESTAREM CORRETOS AO ENTRAR 
// E A SENHA JÁ ESTÁ CRIPTOGRAFADA... 

$resultado = mysqli_query($conex, $query);

$row = mysqli_num_rows($resultado); // SE RETORNAR 1 USUARIO AUTENTICADO

if ($row == 1) {
     $_SESSION['usuario'] = $usuario;// salvar em uma seção para saber se o usuário já foi autenticado e validar internamente na outra pagina
     header ('Location: painel.php');
} else {
    $_SESSION['nao_autenticado'] = true;
    header('Location: index.php'); // se n logar volta para a mesma pagina de login
    exit();
}