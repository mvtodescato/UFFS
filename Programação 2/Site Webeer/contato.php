<?php

$erros=array();

	if(isset($_POST['enviar'])){
		$nome = trim(addslashes($_POST['nome']));
		$email = trim(addslashes($_POST['email']));
		$telefone = $_POST['telefone'];
		$mensagem = $_POST['mensagem'];
		$data = date('Y-m-d');
		if (empty($nome) || !strstr($nome," "))
			$erros[] = "Digite seu nome completo";

		if(empty($email) || !(filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)))
           $erros[] = "Digite um email válido";	
       if (empty($telefone)){
       	$erros[] = "Digite um telefone válido";
       }
       if(empty($mensagem))
       	$erros[] = "Digite uma mensagem válida";
       if(count($erros) == 0){
			include "includes/conexao.php";
			$sql="INSERT INTO ajuda(nome,email,telefone,mensagem,data) VALUES ('$nome','$email','$telefone','$mensagem','$data')";
			mysqli_query($conexao, $sql);
		}
	}


?>
<?php
include "includes/cabecalho.php";
?>

	<div class="container">
		


		<section class="col-1">
			
			<img src="imagens/lateral.jpg" alt="miniatura1" width="300px" height="700px" >
			
		</section>

		<section class="col-2">
			<?php 

		if(isset($erros) and count($erros) > 0){
			echo "<ul>";
			foreach ($erros as $erro) {
				echo "<li style='color:red'>$erro</li>";
			}
			echo "</ul>";
		}
		?>
		<?php 
		if(!(isset($_POST['enviar'])) || count($erros)!=0){
		?>
			<h2>Deixe uma mensagem:</h2>
				<form action="" method="post" id="form-contato">
				    <div class="form-item">
				      <label for="nome" class="label-alinhado">Nome:</label>
				      <input type="text" id="nome" name="nome" size="50" placeholder="Nome completo">
				      <span class="msg-erro" id="msg-nome"></span>
				    </div>		

				<div class="form-item">
				      <label for="email" class="label-alinhado">E-mail:</label>
				      <input type="email" id="email" name="email" placeholder="fulano@dominio" size="50">
				      <span class="msg-erro" id="msg-email"></span>
				</div>
				<div class="form-item">
				      <label for="telefone" class="label-alinhado">Telefone:</label>
				      <input type="text" id="telefone" name="telefone" placeholder="(00)00000-0000" size="14">
				      <span class="msg-erro" id="msg-telefone"></span>
				</div>
				<div class="form-item">
				      <label for="mensagem" class="label-alinhado">Mensagem:</label>
				 </div>
				 <div>
				 	<label for="mensagem" class="label-alinhado"></label>
				      <textarea cols=60 id="mensagem" rows="10" name="mensagem" maxlength="500" wrap="hard" placeholder="Deixe uma mensagem!"></textarea>


				      <span class="msg-erro" id="msg-mensagem"></span>
				</div>	
								    <div class="form-item">
				    	<label class="label-alinhado"></label>
				    <input type="submit" id="botao" value="Confirmar" name="enviar">
				    </div>
			<h2>Contate-nos:</h2>
				<div>
					
					<label class="label-alinhado">Telefone: </label> (49)991015541
					
				</div>
				<div>
					<div>
					<label class="label-alinhado">Email: </label> contato@webeer.com
					
				</div>

			</div>		
			</form>	
		<?php 
			}else{
			echo "<h2>MENSAGEM ENVIADA COM SUCESSO!</h2>";
		}
		?>
		</section>
<section class="col-3">
			<img src="imagens/lateral2.jpg" alt="miniatura1" width="300px" height="700px" >
			
		</section>

	</div>
	<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>
	<script src="js/functions.js"></script>
</body>
</html>