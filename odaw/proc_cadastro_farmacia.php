<?php 
session_start();
include('conex.php');


$nome_pac = mysqli_real_escape_string($conex, $_POST['nome_pac']);
$email = mysqli_real_escape_string($conex, $_POST['email']);
$genero = mysqli_real_escape_string($conex, $_POST['genero']);
$nome_reme = mysqli_real_escape_string($conex, $_POST['nome_reme']);
$tarja = mysqli_real_escape_string($conex, $_POST['tarja']);
$extras = mysqli_real_escape_string($conex, $_POST['extras']);

$query = "insert into farmacia (nome_pac, email, genero, nome_reme, tarja, extras) VALUES ('$nome_pac', '$email', '$genero', '$nome_reme', '$tarja', '$extras'); 
";


$resultado = mysqli_query($conex, $query);



if ($resultado == false) {
        $erro = mysqli_error($conex);
        echo $erro;
} else {
    header("location: cadastrado.php");
}