<?php 
session_start();
include('conex.php');

$query = "select * from farmacia";


$resultado = mysqli_query($conex, $query);


if ($resultado == false) {
        $erro = mysqli_error($conex);
        echo $erro;
} else {
    while ($linha = mysqli_fetch_array($resultado)) {
        echo "<hr>";
        echo "Nome Paciente:" . $linha[1] . "<br>";
        echo "Email:" . $linha[2] . "<br>";
        echo "Genêro:" . $linha[3] . "<br>";
        echo "Nome do remédio:" . $linha[4] . "<br>";
        echo "Tarja do remédio:" . $linha[5] . "<br>";
        echo "Informações extras:" . $linha[6] . "<br>";
    }
}

?>

<html>
<h5><a href="painel.php">Voltar para o painel</a></h5>
</html>