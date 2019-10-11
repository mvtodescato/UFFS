package programa;
class dataValidade{
	int dia, mes, ano;
        void formata(){
            System.out.printf("%02d/%02d/%d\n", this.dia,this.mes,this.ano);
        }
}