library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity SenkronAsenkron_tb is
end SenkronAsenkron_tb;

architecture bench of SenkronAsenkron_tb is

    signal clock   : std_logic := '0';
    signal reset   : std_logic := '0';
    signal enable  : std_logic := '0';
    signal counter : std_logic_vector(7 downto 0);

    constant clock_period : time := 10 ns;

begin

    ----------------------------------------------------------------
    -- DUT
    ----------------------------------------------------------------
    uut : entity work.SenkronAsenkron
        port map (
            clock   => clock,
            reset   => reset,
            enable  => enable,
            counter => counter
        );

    ----------------------------------------------------------------
    -- CLOCK: 100 MHz
    ----------------------------------------------------------------
    clocking : process
    begin
        while true loop
            clock <= '0';
            wait for clock_period / 2;

            clock <= '1';
            wait for clock_period / 2;
        end loop;
    end process;

    ----------------------------------------------------------------
    -- STIMULUS
    ----------------------------------------------------------------
    stimulus : process
    begin

        ----------------------------------------------------------------
        -- TEST 1: Initial condition
        ----------------------------------------------------------------
        reset  <= '0';
        enable <= '0';

        wait for 20 ns;

        assert counter = x"00"
            report "ERROR: Counter should initially be 0"
            severity error;

        ----------------------------------------------------------------
        -- TEST 2: Enable = 0
        ----------------------------------------------------------------
        wait for 30 ns;

        assert counter = x"00"
            report "ERROR: Counter changed while enable = 0"
            severity error;

        ----------------------------------------------------------------
        -- TEST 3: Enable = 1
        ----------------------------------------------------------------
        enable <= '1';

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"01"
            report "ERROR: Counter should be 1"
            severity error;

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"02"
            report "ERROR: Counter should be 2"
            severity error;

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"03"
            report "ERROR: Counter should be 3"
            severity error;

        ----------------------------------------------------------------
        -- TEST 4: Assert synchronous reset between clock edges
        ----------------------------------------------------------------
        reset <= '1';

        wait for 2 ns;

        assert counter = x"03"
            report "ERROR: Synchronous reset changed counter before clock edge"
            severity error;

        ----------------------------------------------------------------
        -- TEST 5: Reset takes effect at next rising edge
        ----------------------------------------------------------------
        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"00"
            report "ERROR: Counter was not reset at rising edge"
            severity error;

        ----------------------------------------------------------------
        -- TEST 6: Release reset and count again
        ----------------------------------------------------------------
        reset  <= '0';
        enable <= '1';

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"01"
            report "ERROR: Counter did not restart from 0"
            severity error;

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"02"
            report "ERROR: Counter should be 2"
            severity error;

        ----------------------------------------------------------------
        -- TEST 7: Disable counting
        ----------------------------------------------------------------
        enable <= '0';

        wait until rising_edge(clock);
        wait for 1 ns;

        assert counter = x"02"
            report "ERROR: Counter changed while enable = 0"
            severity error;

        report "TESTBENCH COMPLETED SUCCESSFULLY"
            severity note;

        wait;

    end process;

end bench;