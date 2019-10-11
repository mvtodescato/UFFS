<?php
include "cabecalhoAdm.php";
?>

<div class="container">
	<main>
		<h2>Exclusão de Produto</h2>
		<?php
		if(isset($_GET['id'])){
			if(is_numeric($_GET['id'])){
				include "includes/conexao.php";
				$sql = "delete from produto where id = {$_GET['id']}";
				$resultado = mysqli_query($conexao, $sql);
				if($resultado){
					echo "<p>Produto excluído com sucesso</p>";
				}
				else{
					echo "<p>O produto não pode ser excluído</p>";
					echo mysqli_error($conexao);
				}
			}
			else{
				echo "<p>O código do produto informado é inválido</p>";
			}
		}
		else{
			echo "<p>Este código de produto não existe</p>";
		}
		?>

	</main>	
	
</div>

