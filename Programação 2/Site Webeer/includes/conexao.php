<?php
$host = "localhost";
$user = "admwebeer";
$senha = "12345";
$database = "webeer";
$conexao = mysqli_connect($host, $user, $senha, $database) or
die("Houve um erro de conexão ao banco de dados.");
mysqli_query($conexao, "SET NAMES 'utf8'");
mysqli_query($conexao, 'SET character_set_connection=utf8');
mysqli_query($conexao, 'SET character_set_client=utf8');
mysqli_query($conexao, 'SET character_set_results=utf8');
?>