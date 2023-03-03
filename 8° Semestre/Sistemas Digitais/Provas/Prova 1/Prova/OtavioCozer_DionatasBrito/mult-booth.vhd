library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;



--entidade de booth
-- a (multiplicando) e b (multiplicador)
-- p (produto da multiplicacao)
-- start (inicio da opecao)	
-- done_tick (termino da operacao)



entity booth_radix4 is
generic (n: integer:=8;
            counter_width: integer:=3);
    Port ( a_in : in  STD_LOGIC_VECTOR (n-1 downto 0); 
           b_in : in  STD_LOGIC_VECTOR (n-1 downto 0); 
           p_out : out  STD_LOGIC_VECTOR (2*n-1 downto 0);
           clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           start : in  STD_LOGIC;
           ready : out STD_LOGIC;
           done_tick : out  STD_LOGIC);
           
end booth_radix4;



architecture Behavioral of booth_radix4 is
	--constantes
--	constant n: integer:=8;
	--constant counter_width: integer:=3;
	
	--sinais
	signal counter_reg, counter_next:  unsigned(counter_width-1 downto 0);
	signal counter_add, counter_reset: std_logic;
	
	--estado
    --idle (em espera)
    --calc (calcula)
    --done (termino)
    type state_type is (idle, calc, done);
    
    --sinais
	signal state_reg, state_next: state_type;
	signal a_reg,a_next: unsigned(2*n-1 downto 0);
	signal b_reg,b_next: STD_LOGIC_VECTOR (n downto 0); 
	alias  triplet: STD_LOGIC_VECTOR (2 downto 0) is b_reg(2 downto 0); 
	signal prod_reg, prod_next: unsigned(2*n downto 0);
	--signal op_reg, op_next: unsigned(2*n downto 0);
	signal soma: unsigned(2*n downto 0);



begin

	process(clk, reset)
	begin
	
	
        --se resert for pro idle, todas as variaveis que foi necessário criar (1) reg e next
        --deve ser zerada
		if reset = '1' then
			state_reg <= idle;
			counter_reg <= (others => '0');
			prod_reg <= (others => '0');
			--op_reg <= (others => '0');
			a_reg <= (others => '0');
		    b_reg <= (others => '0');

		--atualizando os registradores
		elsif clk' event and clk='1' then
			counter_reg <= counter_next;
			state_reg <= state_next;
			a_reg <= a_next;
			b_reg <= b_next;
			
			--aqui esta fazendo o shift para a direita
			prod_reg <= prod_next;

			--op= triplet
			--aqui recebe o valor antes de dar o shift
			--olhando os 3 ultimos bits irá dizer qual operacao deve ser realizada
			--op_reg <= prod_next; 
		end if;
	end process;


   --p_out <= prod_reg;
--Aqui eh onde a magia acontece
	process(state_reg, prod_reg, a_in, b_in, start, counter_reg,soma)
	begin
	  --counter_add <= '0';
	  --counter_reset <= '0';
	  done_tick <= '0';
	  state_next <= state_reg;
	  prod_next <= prod_reg;
	  a_next <= a_reg;
	  b_next <= b_reg;
	  ready<='0';

      case(state_reg) is
	       when idle =>
	       ready<='1';
			--carrega os registradores
			--vai para o estado que realiza a multiplicacao
                if start = '1' then 
                    a_next(n-1 downto 0) <= unsigned(a_in);
                    a_next(2*n-1 downto n) <= (others => '0');
                    prod_next<= (others => '0');
                    b_next(n downto 1) <= (b_in);
                    b_next(0) <= '0';
                    state_next <= calc;
                    counter_next<= (others => '0');
                    
                end if;
                
		   when calc =>
		   prod_next<=soma;
		   a_next<=a_reg(2*n-3 downto 0) & "00";
		   b_next<="00" & b_reg(n downto 2); -- OLHAR DEPOIS
		   --para calcular
           --eh adicionado +1 ao contador (counter_add)
           --caso ele seja igual a 4, significa que as operacos acabaram
           --vai para o estado que realiza a multiplicacao
              -- counter_add <= '1'; 
               if (counter_reg = n/2) then
                   state_next <= done;
                 else
                 counter_next<=counter_reg +1;
                  
               end if;



           --Aqui esta a parte do multiplicadorde numeros positivos de Booth Radix4
           --Depenendo dos ultimos 3 bits vai ser realizado uma determinada operacao
           --000 = faz nada
           --001 = soma multiplicando
           --010 = soma multiplicando
           --011 = soma dobro multiplicando
           --100 = subtrai dobro multiplicando
           --101 = subtrai multiplicando
           --110 = subtrai multiplicando
           --111 = faz nada

           
	--counter_next <= (others => '0') when counter_reset = '1' 
                                 --else counter_reg + 1 when counter_add = '1'
                         --  else counter_reg;    
		   when done =>
               -- p_out <= std_logic_vector(prod_next(2*n) & prod_next(2*n downto 2));
                done_tick <= '1';
                --counter_add <= '0';
                --counter_reset <= '1';
                state_next <= idle;
	  end case;
	  
	end process;
	
	
	process( prod_reg,a_reg,triplet)
    begin	
	case (triplet) is
                   --            soma <= soma(2*n) & soma(2*n downto 1); 
                   --soma multiplicando
                   when "001" | "010" =>
                       soma <= 
                       ((prod_reg) + (a_reg));
                   
    
                   --soma dobro multiplicando
                   when "011" =>
                       soma <= 
                       ((prod_reg) + (a_reg(2*n-2 downto 0) & '0'));
                   
                   --subtrai o multiplicando
                   when "101" | "110" => 
                       soma <=
                       (prod_reg - (a_reg));
                   
    
                   --faz nada
                   when "100" =>  --Subtrair o dobro do multiplicando
                       soma <=
                       ((prod_reg) -(a_reg(2*n-2 downto 0) & '0'));
                   
                   --SHIFT  (para a direita)
                   when others =>
                   soma<=prod_reg;
           
               end case;
           
 end process;			
 
 p_out<=std_logic_vector(prod_reg(2*n - 1 downto 0));		  
end Behavioral;


