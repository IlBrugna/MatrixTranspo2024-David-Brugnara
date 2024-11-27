# README

## Overview

This project involves running simulations using `.pbs` scripts for job submission on a cluster. Two `.pbs` files are provided:

1. matrix.pbs: Used for general testing.
2. tagsAndBlocks.pbs: Focuses on comparing different implicit implementations.

The main code includes two distinct test loops, corresponding to the two `.pbs` files. By default, the second loop is commented out. Additionally, there is a function to validate the correctness of the parallel implementation’s transposition, which is also commented out by default.

## How to Run the Simulation

1. **Copy Files**: Copy all relevant files to your cluster directory.
2. **Specify File Locations**: Update the file paths inside the chosen `.pbs` script to match your cluster directory. 
3. **Adjust Configuration**: If needed modify the enviroment variables in the `.pbs` such as desired queue. 
4. **Submit the Job**:
   - Use the `qsub` command to submit the job.
   - Example: To run the general test, use the command:
     qsub matrix.pbs
