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
   
   signal y: std_logic_vector(32-1 downto 0);
   signal x0: std_logic_vector(32-1 downto 0):= X"000000ff";--:="16#000000FF#";
   signal x1: std_logic_vector(32-1 downto 0):= X"0000ff00";
   signal x2: std_logic_vector(32-1 downto 0):= X"00ff0000";
   signal x3: std_logic_vector(32-1 downto 0):= X"ff000000";
   
   signal s: std_logic_vector(2-1 downto 0);
   signal en: std_logic:='0';
   
   signal en_pwm: std_logic;
   signal freq_pwm: std_logic_vector(7 downto 0):=X"0f";
   signal duty_pwm: std_logic_vector(7 downto 0):=x"05";
   signal y2,clr_pwm: std_logic;
   
   signal tmp_pwm: std_logic_vector(7 downto 0);
   
begin
-- UUT

    uut_1: entity work.mux_ahe
    port map(
    x0=>x0,
    x1=>x1,
    x2=>x2,x3=>x3,
    s=>s,
    en=>en,
    y=>y
    );
    
    
 -- test PWM module
 
    uut_2: entity work.pwm_ahe
    generic map(n=>8)
    port map(
    clk=>Clk,
    en=>en_pwm,
    clr=>clr_pwm,
    duty=>duty_pwm,
    freq=>freq_pwm,
    tmp=>tmp_pwm,
    y=>y2
    );
    
    
---- and gate testing: basic sim design
--    uut_0: entity work.ahe_and 
--    port map(
--    a => a,
--    b => b,
--    c => c
--    );



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
      
      wait for Clk_period; --clock
      
-- UUT2 test conditions
        clr_pwm <='1';
        en_pwm <='1';
       wait for Clk_period; --clock
       clr_pwm <='0';
        
      
-- UUT1 Test conditions
--      -- en = 1
--        en <= '1';
--            s <= "00";  
--            wait for Clk_period;
            
--            s <= "01";  
--            wait for Clk_period;
            

--            s <= "10";  
--            wait for Clk_period;
            
--            s <= "11";  
--            wait for Clk_period;
            
--            en <= '0';  
--            wait for Clk_period;
          
       
      wait;
   end process;

end Behavioral;
