<?php

include('verifica_login.php');
?>

<h5>Olá Sr. <?php echo $_SESSION['usuario'];?></h5>

<h5><a href="cadastro_farmacia.php">Cadastrar Pacientes</a></h5>

<h5><a href="listar_dados.php">Listar Dados</a></h5>

<h5><a href="logout.php">Vazar</a></h5>