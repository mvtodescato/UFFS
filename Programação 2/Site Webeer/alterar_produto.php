<?php
include "includes/conexao.php";

if(isset($_POST['alterar'])){

	$nome = addslashes($_POST['nome']);
	$imagem = (empty($_FILES['arquivo']['name']))? 'imagem' : "'{$_FILES['arquivo']['name']}'"; 
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

	if($catPilsen == 0 & $catVienna == 0 & $catWeiss == 0 & $catAmericanipa == 0 & $catOutros == 0){
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

	if(!empty($_FILES['arquivo']['name'])){
		$destino = "imagens/produtos/".$_FILES['arquivo']['name'];
		if(!move_uploaded_file($_FILES['arquivo']['tmp_name'], $destino)){
			$erros[] = "Falha no upload do arquivo";
		}
	}

	if (count($erros) == 0){ 
	 	$sql = "UPDATE produto SET nome = '$nome', imagem = $imagem, descricao = '$descricao', catPilsen = $catPilsen, catVienna = $catVienna, catWeiss = $catWeiss, catAmericanipa = $catAmericanipa, catOutros = $catOutros, qtde = $quantidade, valor = $valor, desconto = $desconto WHERE id = {$_GET['id']}";
		$resultado = mysqli_query($conexao, $sql);
		if($resultado){
			$mensagem = "O produto <strong>$nome</strong> foi alterado com sucesso";
		}
		else{
			$mensagem = "Erro. O produto não pôde ser alterado. ";
			$mensagem .= mysqli_error($conexao); 
		}
	} 
}
else{ 
	$sql = "select * from produto where id = {$_GET['id']}";
	$resultado = mysqli_query($conexao, $sql);
	$dados = mysqli_fetch_array($resultado);
}

include "cabecalhoAdm.php";
include "includes/functions.php";
?>


		<div class="container">
			<main>
				<h2>Alteração de Produtos</h2>
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
								value="<?=isset($_POST['nome']) ? $_POST['nome'] : $dados['nome'];?>">								
							</div>
							
							
							<div class="form-item">
								<label for="arquivo" class="label-alinhado">Selecione uma imagem:</label>
								<input type="file" name="arquivo" id="arquivo">
								<small><em>* deixe em branco para manter a imagem atual</em></small>
							    <div class="produto">								  
									<figure>
										<img src="imagens/produtos/<?=mostraImagem($dados['imagem']);?>" alt="<?=$dados['nome'];?>">					
									</figure>							
							    </div> 								
							</div>

							<div class="form-item">
								<label for="desc" class="label-alinhado">Descrição:</label>
								<textarea name="descricao" rows="5" cols="30" id="desc">
									<?=isset($_POST['descricao']) ? $_POST['descricao'] : $dados['descricao'];?></textarea>
							</div>
							<div class="form-item">
								<label class="label-alinhado">Categorias:</label>
								<label><input type="checkbox" id="pilsen" name="pilsen" 
									<?=isset($_POST['pilsen'])? "checked":($dados['catPilsen'] == 1)? "checked": '';?>>Pilsen</label>
								<label><input type="checkbox" id="vienna" name="vienna"
									<?=isset($_POST['vienna'])? "checked":($dados['catVienna'] == 1)? "checked": '';?>>Vienna</label>
								<label><input type="checkbox" id="weiss" name="weiss"
									<?=isset($_POST['weiss'])? "checked":($dados['catWeiss'] == 1)? "checked": '';?>>Weiss</label>
								<label><input type="checkbox" id="americanipa" name="americanipa"
									<?=isset($_POST['americanipa'])? "checked":($dados['catAmericanipa'] == 1)? "checked": '';?>>AmericanIPA</label>
								<label><input type="checkbox" id="outros" name="outros"
									<?=isset($_POST['outros'])? "checked":($dados['catOutros'] == 1)? "checked": '';?>>Outros</label>
							</div>						
						</fieldset>
						<fieldset>
							<legend><strong>Dados da locação</strong></legend>
							<div class="form-item">
								<label for="qntDis" class="label-alinhado">Quantidade Disponível:</label>
								<input type="number" id="quantidade" name="quantidade" value="<?=isset($_POST['quantidade'])? $_POST['quantidade']:$dados['qtde'];?>" min="1">
							</div>
							<div class="form-item">
								<label for="valor" class="label-alinhado">Valor da locação:</label>
								<input type="text" id="valor" name="valor" placeholder="0.00" value="<?=isset($_POST['valor'])? $_POST['valor']:$dados['valor'];?>" 
								onchange="calculaTotal()">
							</div>
							<div class="form-item">
								<label for="desconto" class="label-alinhado">Desconto promocional:</label>
								<input type="text" id="desconto" name="desconto" value="<?=isset($_POST['desconto'])? $_POST['desconto']:$dados['desconto'];?>" 
								onchange="calculaTotal()">
							</div>
							<div class="form-item">						
								<label for="total" class="label-alinhado">Total:</label>
								<div id="total"><?=($dados['valor'] - $dados['desconto']);?></div>
							</div>

							<div class="form-item">
						    	<label class="label-alinhado"></label>
						    	<input type="submit" id="botao" value="Alterar" 
						    	name="alterar">
						    	<input type="reset" value="Redefinir">
						    </div>						
						</fieldset>
					</div>
				</form>
				<?php
			} 
			?>
			</main>	
			
		