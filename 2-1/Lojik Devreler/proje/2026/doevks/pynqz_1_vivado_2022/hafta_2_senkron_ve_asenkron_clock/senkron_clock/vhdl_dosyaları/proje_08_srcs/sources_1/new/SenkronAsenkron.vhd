library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity SenkronAsenkron is
    Port (
        clock   : in  std_logic;
        reset   : in  std_logic;
        enable  : in  std_logic;
        counter : out std_logic_vector(7 downto 0)
    );
end SenkronAsenkron;

architecture Behavioral of SenkronAsenkron is

    signal count_reg : unsigned(7 downto 0) := (others => '0');

begin

    process(clock)
    begin
        if rising_edge(clock) then
            if reset = '1' then
                count_reg <= (others => '0');
            elsif enable = '1' then
                count_reg <= count_reg + 1;
            end if;
        end if;
    end process;

    counter <= std_logic_vector(count_reg);

end Behavioral;