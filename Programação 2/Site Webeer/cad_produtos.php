
<?php
include "includes/conexao.php";

if(isset($_POST['cadastrar'])){

	$nome = addslashes($_POST['nome']);
	$imagem = (empty($_FILES['arquivo']['name']))? 'NULL' : "'{$_FILES['arquivo']['name']}'"; 
	$descricao = addslashes($_POST['descricao']);
	$catPilsen = isset($_POST['pilsen'])? 1 : 0;
	$catVienna = isset($_POST['vienna'])? 1 : 0;
	$catWeiss = isset($_POST['weiss'])? 1 : 0;
	$catAmericanipa = isset($_POST['americanipa'])? 1 : 0;
	$catOutros = isset($_POST['outros'])? 1 : 0;
	$quantidade = $_POST['quantidade'];
	$valor = str_replace(",", ".", $_POST['valor']);
	$desconto = str_replace(",", ".", $_POST['desconto']);

	$erros = array();

	if(empty($nome)){
		$erros[] = "O nome do produto não pode ser vazio";
	}

	if($catPilsen == 0 & $catVienna == 0 & $catWeiss== 0 & $catAmericanipa == 0 & $catOutros == 0){
		$erros[] = "É necessário selecionar pelo menos 1 categoria";
	}

	if(!is_numeric($valor)){
		$erros[] = "Valor da locação inválido";
		$valor = 0;
	}

	if(!is_numeric($desconto)){
		$erros[] = "Valor do desconto inválido";
		$desconto = 0;
	}

	if($valor - $desconto <=0){
		$erros[] = "O valor final deve ser maior do que zero";
	}

	if($imagem <> 'NULL'){
		$destino = "imagens/produtos/".$_FILES['arquivo']['name'];
		if(!move_uploaded_file($_FILES['arquivo']['tmp_name'], $destino)){
			$erros[] = "Falha no upload do arquivo";
		}
	}

	if (count($erros) == 0){ 
	 	echo $sql = "INSERT INTO produto (nome, imagem, descricao, catPilsen, catVienna, catWeiss, catAmericanipa, catOutros, qtde, valor, desconto) VALUES
	('$nome', $imagem, '$descricao', $catPilsen, $catVienna, $catWeiss, $catAmericanipa, $catOutros, $quantidade, $valor, $desconto)";
		$resultado = mysqli_query($conexao, $sql);
		if($resultado){
			$mensagem = "O produto <strong>$nome</strong> foi inserido com sucesso";
		}
		else{
			$mensagem = "Erro. O produto não pôde ser cadastrado. ";
			$mensagem .= mysqli_error($conexao); 
		}
	} 
}
include "cabecalhoAdm.php";
?>


		<div class="container">
			<main>
				<h2>Cadastro de Produtos</h2>
				<?php
				if (isset($mensagem)){
					echo "<p>$mensagem</p>";
				}
				else{
					if(isset($erros)){
						echo "<ul>";
						foreach ($erros as $erro){
							echo "<li style='color: red;'>$erro</li>";
						}
						echo "</ul>";
					}
				?>
				<form action="" method="post" id="form-cadastro" enctype="multipart/form-data" 
				onsubmit="cadastroProduto()">
					<div>
						<fieldset>
							<legend><strong>Dados do Produto</strong></legend>
							<div class="form-item">
								<label for="nome" class="label-alinhado">Nome:</label>
								<input type="text" id="nome" name="nome" size="50" autofocus 
								value="<?=isset($_POST['nome']) ? $_POST['nome'] : '';?>">								
							</div>
							

							
							<div class="form-item">
								<label for="arquivo" class="label-alinhado">Selecione uma imagem:</label>
								<input type="file" name="arquivo" id="arquivo">
							</div>

							<div class="form-item">
								<label for="desc" class="label-alinhado">Descrição:</label>
								<textarea name="descricao" rows="5" cols="30" id="desc"><?=isset($_POST['descricao']) ? $_POST['descricao'] : '';?></textarea>
							</div>

							<div class="form-item">
								<label class="label-alinhado">Categorias:</label>
								<label><input type="radio" id="pilsen" name="pilsen" 
									<?=isset($_POST['pilsen'])? "checked":'';?>>Pilsen</label>
								<label><input type="radio" id="vienna" name="vienna"
									<?=isset($_POST['vienna'])? "checked":'';?>>Vienna</label>
								<label><input type="radio" id="weiss" name="weiss"
									<?=isset($_POST['weiss'])? "checked":'';?>>Weiss</label>
								<label><input type="radio" id="americanipa" name="americanipa"
									<?=isset($_POST['americanipa'])? "checked":'';?>>AmericanIPA</label>
								<label><input type="radio" id="outros" name="outros"
									<?=isset($_POST['outros'])? "checked":'';?>>Outros</label>
							</div>						
						</fieldset>
						<fieldset>
							<legend><strong>Dados da locação</strong></legend>
							<div class="form-item">
								<label for="qntDis" class="label-alinhado">Quantidade Disponível:</label>
								<input type="number" id="quantidade" name="quantidade" value="<?=isset($_POST['quantidade'])? $_POST['quantidade']:1;?>" min="1">
							</div>
							<div class="form-item">
								<label for="valor" class="label-alinhado">Valor da locação:</label>
								<input type="text" id="valor" name="valor" placeholder="0.00" value="<?=isset($_POST['valor'])? $_POST['valor']:'';?>" 
								onchange="calculaTotal()">
							</div>
							<div class="form-item">
								<label for="desconto" class="label-alinhado">Desconto promocional:</label>
								<input type="text" id="desconto" name="desconto" value="<?=isset($_POST['desconto'])? $_POST['desconto']:'0.00';?>" 
								onchange="calculaTotal()">
							</div>
							<div class="form-item">						
								<label for="total" class="label-alinhado">Total:</label>
								<div id="total">0.00</div>
							</div>

							<div class="form-item">
						    	<label class="label-alinhado"></label>
						    	<input type="submit" id="botao" value="Cadastrar" 
						    	name="cadastrar">
						    	<input type="reset" value="Limpar">
						    </div>						
						</fieldset>
					</div>
				</form>
				<?php
			} 
			?>
			</main>	
		
		
		</div>

		<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>

