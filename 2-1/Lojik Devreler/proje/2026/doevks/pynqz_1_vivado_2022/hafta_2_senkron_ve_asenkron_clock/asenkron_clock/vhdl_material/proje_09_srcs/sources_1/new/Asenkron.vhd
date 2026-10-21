library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;


entity Asenkron is
  Port ( 
  clock: in std_logic;
  reset: in std_logic;
  enable: in std_logic;
  counter: out std_logic_vector(7 downto 0)
  
  );
end Asenkron;


architecture Behavioral of Asenkron is
    signal counter_reg: std_logic_vector(7 downto 0) := (others => '0');
begin
    process(clock, reset)
    begin
        if reset = '1' then
            counter_reg(0) <= '0';
        elsif rising_edge(clock) then
            if enable = '1' then
                counter_reg(0) <= not counter_reg(0);
            end if;
        end if;
    end process;
    
    
    --Ripple Stage: Önceki bitin falling edge'i ile toggle oluşu
    gen_ripple: for i in 1 to 7 generate --Fonksiyon?
    begin
        process(counter_reg(i-1), reset)
        begin
            if reset = '1' then
                counter_reg(i) <= '0';
            elsif falling_edge(counter_reg(i-1)) then
                counter_reg(i) <= not counter_reg(i);
            end if;
        end process;
    end generate;
    
counter <= counter_reg;
end Behavioral;
