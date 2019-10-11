<?php
session_start();
if(@array_key_exists($_GET['id'], $_SESSION['carrinho'])){
    $_SESSION['carrinho'][$_GET['id']]['quantidade'] += $_GET['quantidade'];     
}
else{
    $_SESSION['carrinho'][$_GET['id']] = array("nome" => $_GET['nome'], 
                                                "quantidade" => $_GET['quantidade'],
                                                "valorFinal" => $_GET['valorFinal']);
}
echo count($_SESSION['carrinho']);
?>