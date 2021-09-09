<?php
session_start();

if (!$_SESSION['usuario']) { // ESSE ARQUIVO SERVE PARA VERFICAR O LOGIN E NÃO PODER TER ACESSO AO PAINEL SEM QUE HAJA UM LOGIN VALIDO
    header('Location: index.html');
    exit();
}