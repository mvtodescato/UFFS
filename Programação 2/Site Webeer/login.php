<?php
include "includes/cabecalho.php";
?>


	<div class="container">
		
		<section class="col-1">
			
		</section>
		<section class="col-2">
	 	<h2>Identifique-se</h2>

			<form class="login" action="verificacao.php" method="post">
				<div class="form-item">
					<label for="login" class="label-alinhado">Login:</label>
					<input type="text" id="login" name="login">
				</div>
				<div class="form-item">
					<label for="senha" class="label-alinhado">Senha:</label>
					<input type="password" id="senha" name="senha">				
				</div>
				<div class="msg-erro" id="msg-senha">
				  <?php
			        if(isset($_GET['erro'])){
			          if($_GET['erro'] == 1)
			            echo "Login incorreto";
			          elseif($_GET['erro'] == 2)
			            echo "Senha incorreta";
			        }
			        ?>	
			    </div>
			    <div class="form-item">
			    	<label for="senha" class="label-alinhado"></label>
					<input type="submit" id="botao" value="Entrar">
				</div>
			</form>
			<div class="teste">
				<p><a href="cad.php"><br>Quero me Cadastrar</p></a>
			</div>					
		</section>
	</div>
	<section class="col-3">
		
	</section>	
		<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>

