<?php

$erros=array();

	if(isset($_POST['cadastrar'])){
		$nome = trim(addslashes($_POST['nome']));
		$cpf = trim(addslashes($_POST['cpf']));
		$email = trim(addslashes($_POST['email']));
		$telefone = trim(addslashes($_POST['telefone']));
		$login = trim(addslashes($_POST['login']));
		$senhauser = trim(addslashes($_POST['senha']));
		$rua = trim(addslashes($_POST['rua']));
		$bairro = trim(addslashes($_POST['bairro']));
		$estado = trim(addslashes($_POST['estado']));
		$cidade = trim(addslashes($_POST['cidade']));
		$numero = trim(addslashes($_POST['numero']));
		$complemento = trim(addslashes($_POST['complemento']));
		$cep = trim(addslashes($_POST['cep']));

			include "includes/conexao.php";
			$nova = sha1($senhauser);
			 $nova;	
			 $sql="INSERT INTO cliente (nome, email, telef,cpf,login, senha) VALUES ('$nome', '$email', '$telefone', '$cpf', '$login', '$nova')";
			$resultado = mysqli_query($conexao, $sql);
			if($resultado){
			$sql = "select id from cliente order by id desc limit 1";
			$resultado = mysqli_query($conexao, $sql);
			$idcliente = mysqli_fetch_array($resultado)[0];
			$sql="INSERT INTO ender (idCliente,rua,bairro,uf,cidade,numero,complemento,CEP) VALUES ('$idcliente','$rua', '$bairro', '$estado', '$cidade', '$numero', '$complemento', '$cep')";
			mysqli_query($conexao, $sql);
			header("Location: login.php");

		}
	}
?>

<?php
include "includes/cabecalho.php";
?>

	<div class="container">
		
		<section class="col-1">

			</section>



		<section class="col-2">
			<h2>Cadastre-se</h2>
			<div>
				<form action="" method="post" id="form-contato">
				    <div class="form-item">
				      <label for="nome" class="label-alinhado">Nome:</label>
				      <input type="text" id="nome" name="nome" size="50" placeholder="Nome completo" value="<?=isset($nome) ? $nome : '';?>">
				      <span class="msg-erro" id="msg-nome"></span>
				    </div>
				    <div class="form-item">
				      <label for="email" class="label-alinhado">E-mail:</label>
				      <input type="email" id="email" name="email" placeholder="fulano@dominio" size="50" value="<?=isset($email) ? $email : '';?>">
				      <span class="msg-erro" id="msg-email"></span>
				    </div>
				    <div class="form-item">
				      <label for="telefone" class="label-alinhado">Telefone:</label>
				      <input type="text" id="telefone" name="telefone" placeholder="(00)00000-0000" size="14" value="<?=isset($telefone) ? $telefone : '';?>">
				      <span class="msg-erro" id="msg-telefone"></span>
				    </div>
				    <div class="form-item">
				      <label for="cpf" class="label-alinhado">CPF:</label>
				      <input type="text" id="cpf" name="cpf" placeholder="000.000.000-00" size="14" value="<?=isset($cpf) ? $cpf : '';?>">
				      <span class="msg-erro" id="msg-cpf"></span>
				    </div>
				    <h2>Endereço</h2>					    
				    <div class="form-item">
				      <label for="rua" class="label-alinhado">Rua:</label>
				      <input type="text" id="rua" name="rua" placeholder="Rua, Av..." size="50" value="<?=isset($rua) ? $rua : '';?>">
				      <span class="msg-erro" id="msg-rua"></span>
				    </div>	
				    <div class="form-item">
				      <label for="numero" class="label-alinhado">Numero:</label>
				      <input type="number" id="numero" name="numero" placeholder="Numero" value="<?=isset($numero) ? $numero : '';?>">
				      <span class="msg-erro" id="msg-numero"></span>
				    </div>
				    <div class="form-item">
				      <label for="bairro" class="label-alinhado">Bairro:</label>
				      <input type="text" id="bairro" name="bairro" placeholder="bairro" value="<?=isset($bairro) ? $bairro : '';?>">
				      <span class="msg-erro" id="msg-bairro"></span>
				    </div>
				    <div class="form-item">
				      <label for="cidade" class="label-alinhado">Cidade:</label>
				      <input type="text" id="cidade" name="cidade" size="50" value="<?=isset($cidade) ? $cidade : '';?>">
				      <span class="msg-erro" id="msg-cidade"></span>
				    </div>
				    <div class="form-item">
				      <label for="estado" class="label-alinhado">Estado:</label>
				      <select name="estado" id="estado">
					    <option value="">Selecione o estado</option>
					    <option <?=(isset($estado)) ? (($estado == "Acre") ? "selected":"") : "";?>>Acre</option>
					    <option <?=(isset($estado)) ? (($estado == "Alagoas") ? "selected":"") : "";?>>Alagoas</option>
					    <option <?=(isset($estado)) ? (($estado == "Amapa") ? "selected":"") : "";?>>Amapa</option>
					    <option <?=(isset($estado)) ? (($estado == "Amazonas") ? "selected":"") : "";?>>Amazonas</option>
					    <option <?=(isset($estado)) ? (($estado == "Bahia") ? "selected":"") : "";?>>Bahia</option>
					    <option <?=(isset($estado)) ? (($estado == "Ceara") ? "selected":"") : "";?>>Ceara</option>
					    <option <?=(isset($estado)) ? (($estado == "Distrito Federal") ? "selected":"") : "";?>>Distrito Federal</option>
					    <option <?=(isset($estado)) ? (($estado == "Espirito Santo") ? "selected":"") : "";?>>Espirito Santo</option>
					    <option <?=(isset($estado)) ? (($estado == "Goias") ? "selected":"") : "";?>>Goias</option>
					    <option <?=(isset($estado)) ? (($estado == "Maranhao") ? "selected":"") : "";?>>Maranhao</option>
					    <option <?=(isset($estado)) ? (($estado == "Mato Grosso") ? "selected":"") : "";?>>Mato Grosso</option>
					    <option <?=(isset($estado)) ? (($estado == "Mato Grosso do Sul") ? "selected":"") : "";?>>Mato Grosso do Sul</option>
					    <option <?=(isset($estado)) ? (($estado == "Minas Gerais") ? "selected":"") : "";?>>Minas Gerais</option>
					    <option <?=(isset($estado)) ? (($estado == "Paraiba") ? "selected":"") : "";?>>Paraiba</option>
					    <option <?=(isset($estado)) ? (($estado == "Parana") ? "selected":"") : "";?>>Parana</option>
					    <option <?=(isset($estado)) ? (($estado == "Pernambuco") ? "selected":"") : "";?>>Pernambuco</option>
					    <option <?=(isset($estado)) ? (($estado == "Piaui") ? "selected":"") : "";?>>Piaui</option>
					    <option <?=(isset($estado)) ? (($estado == "Rio de Janeiro") ? "selected":"") : "";?>>Rio de Janeiro</option>
					    <option <?=(isset($estado)) ? (($estado == "Rio Grande do Norte") ? "selected":"") : "";?>>Rio Grande do Norte</option>
					    <option <?=(isset($estado)) ? (($estado == "Rio Grande do Sul") ? "selected":"") : "";?>>Rio Grande do Sul</option>
					    <option <?=(isset($estado)) ? (($estado == "Rondonia") ? "selected":"") : "";?>>Rondonia</option>
					    <option <?=(isset($estado)) ? (($estado == "Roraima") ? "selected":"") : "";?>>Roraima</option>
					    <option <?=(isset($estado)) ? (($estado == "Santa Catarina") ? "selected":"") : "";?>>Santa Catarina</option>
					    <option <?=(isset($estado)) ? (($estado == "Sao Paulo") ? "selected":"") : "";?>>Sao Paulo</option>
					    <option <?=(isset($estado)) ? (($estado == "Sergipe") ? "selected":"") : "";?>>Sergipe</option>
					    <option <?=(isset($estado)) ? (($estado == "Tocantins") ? "selected":"") : "";?>>Tocantins</option>
					  </select>
					  <span class="msg-erro" id="msg-estado"></span>
				    </div>			    
				    <div class="form-item">
				      <label for="cep" class="label-alinhado">CEP:</label>
				      <input type="text" id="cep" name="cep" placeholder="00.000-000" size="10" value="<?=isset($cep) ? $cep : '';?>">
				      <span class="msg-erro" id="msg-bairro2"></span>
				    </div>
				    <div class="form-item">
				      <label for="complemento" class="label-alinhado">Complemento:</label>
				      <input type="text" id="complemento" name="complemento" size="50" value="<?=isset($complemento) ? $complemento : '';?>">
				      <span class="msg-erro" id="msg-complemento"></span>
				    </div>
				    <h2>Login</h2>
				    <div class="form-item">
				      <label for="senha" class="label-alinhado">Login:</label>
				      <input type="text" id="login" name="login" placeholder="Mínimo 6 caracteres" value="<?=isset($login) ? $login : '';?>">
				      <span class="msg-erro" id="msg-login"></span>
				    </div>				    
				    <div class="form-item">
				      <label for="senha" class="label-alinhado">Senha:</label>
				      <input type="password" id="senha" name="senha" placeholder="Mínimo 6 caracteres" value="<?=isset($senha) ? $senha : '';?>">
				      <span class="msg-erro" id="msg-senha"></span>
				    </div>
				    <div class="form-item">
				      <label for="senha2" class="label-alinhado">Repita a Senha:</label>
				      <input type="password" id="senha2" name="senha2" placeholder="Mínimo 6 caracteres">
				      <span class="msg-erro" id="msg-senha2"></span>
				    </div>
				    <div class="form-item">
				      <label class="label-alinhado"></label>
				      <label><input type="checkbox" id="concordo" name="concordo"> Li e estou de acordo com os termos de uso do site</label>
				      <span class="msg-erro" id="msg-concordo"></span>
				    </div>				    
				   <div class="form-item">
			    	<label class="label-alinhado"></label>
			    	<input type="submit" id="botao" value="Confirmar" name="cadastrar">
			    	</div>
				</form>
			</div>			
		</section>

	</div>
	<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>

	<script src="js/cad_cliente.js"></script>
</body>
</html>