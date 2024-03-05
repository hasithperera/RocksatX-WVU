----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/03/2024 05:58:13 PM
-- Design Name: 
-- Module Name: cntr_ahe - Behavioral
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity cntr_ahe is
GENERIC ( n : NATURAL := 32 );
Port ( 
clk: in std_logic;
cnt: out std_logic_vector(n-1 downto 0);
rst: in std_logic
);
end cntr_ahe;

architecture Behavioral of cntr_ahe is
signal tmp_cnt: std_logic_vector(n-1 downto 0):= (others => '0');

begin



process(rst,clk)
begin
    if rst = '1' then
        tmp_cnt <=  (others => '0');
    elsif (clk'event AND clk = '1') then
        tmp_cnt <= tmp_cnt + 1;
    end if;
    
end process;
cnt <= tmp_cnt;

end Behavioral;
