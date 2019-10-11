<?php
  include "includes/conexao.php";
  $login = $_POST["login"];
  $sql = "select id, nome, login, senha from cliente where login = '$login'";
  $resultado = mysqli_query($conexao, $sql);
  if(( mysqli_num_rows($resultado) == 0 )and $login != "admwebeer")
    header("Location: login.php?erro=1");
  elseif($login == "admwebeer"){
    $senha = $_POST["senha"];
    if($senha == "123456"){
      session_start();
      $_SESSION["login"] = $login;   
      $_SESSION["nome"] = "Administrador";
      header("Location: PagAdm.php");
    }else
      header("Location: login.php?erro=2");
  }else{
    $user = mysqli_fetch_array($resultado);
    $senha2 = sha1($_POST["senha"]);
    if($user["senha"] == $senha2){
      session_start();
      $_SESSION["login"] = $login;
      $_SESSION["nome"] = $user["nome"];
      $_SESSION["id"] = $user["id"];
      header("Location: index.php");
    }else{
      header("Location: login.php?erro=2");
    }
  }
?>
 