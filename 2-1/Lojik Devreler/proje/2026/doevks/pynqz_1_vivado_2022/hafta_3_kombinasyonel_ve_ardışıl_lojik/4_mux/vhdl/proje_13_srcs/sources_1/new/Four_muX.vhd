library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

entity Four_muX is
  Port ( 
    Control : in std_logic_vector(31 downto 0);
    Result : out std_logic_vector(31 downto 0)
  );
end Four_muX;


architecture Behavioral of Four_muX is
    signal y: std_logic;
begin
    with Control(5 downto 4) select
        y <= Control(0) when "00",
             Control(1) when "01",
             Control(2) when "10",
             Control(3) when others; --by others 11 is meant.
             
        Result <= (31 downto 1 => '0') & y; --şu kodun açıklamasını daha net yazalım
end Behavioral;
