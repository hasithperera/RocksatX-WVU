----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/03/2024 11:37:59 AM
-- Design Name: 
-- Module Name: ahe_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ahe_tb is
--  Port ( );
end ahe_tb;

architecture Behavioral of ahe_tb is
   signal Clk : std_logic := '0';
   constant Clk_period : time := 10 ns;
   
   signal a,b,c: std_logic:='0';
begin
-- UUT

    uut: entity work.ahe_and 
    port map(
    a => a,
    b => b,
    c => c
    );


 -- Clock process definitions
   Clk_process :process
   begin
        Clk <= '0';
        wait for Clk_period/2;
        Clk <= '1';
        wait for Clk_period/2;
   end process;
   
   -- Stimulus process
   stim_proc: process
   begin       
      wait for Clk_period*1;
        a <= '0';
        b <=  '0';
        wait for Clk_period; --add A and B
        
        a <= '1';
        b <=  '0';
        wait for Clk_period; --add A and B
       
        a <= '0';
        b <=  '1';
        wait for Clk_period; --add A and B
        
        a <= '1';
        b <=  '1';
        wait for Clk_period; --add A and B
        
      wait;
   end process;

end Behavioral;
