<?php
include "cabecalhoAdm.php";
?>

<div class="container">
	<main>
		<h2>Relatório de Produtos</h2>
		<p>| <a href="cad_produtos.php">inserir novo</a> |</p>
		<table>
			<tr>
				<th>Nome </th>
				<th>Valor da locação</th>
				<th>Ação</th>
			</tr>
			<?php
			include "includes/conexao.php";
			include "includes/functions.php";
			$sql = "select produto.id, produto.nome, valor, desconto, (valor - desconto) as valorFinal from produto";
			$resultado = mysqli_query($conexao, $sql);				
			if( mysqli_num_rows($resultado) == 0){
				?>
				<tr>
					<td colspan="4">Nenhum produto encontrado.</td>
				</tr>
				<?php	
			}
			else{
				while($prod = mysqli_fetch_array($resultado)){
					?>				
					<tr>
						<td><?=$prod['nome']; ?></td>
						<td><?=mostraPreco($prod['valor'], $prod['desconto']) ?></td>
						<td>| <a href="alterar_produto.php?id=<?=$prod['id'];?>">alterar</a> | 
							  <a href="excluir_produto.php?id=<?=$prod['id'];?>"> excluir</a> |</td>
					</tr>
					<?php
				} 
			} 
			?>
			</table>

	</main>
</div>



