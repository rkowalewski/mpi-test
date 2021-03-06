#include <mpi.h>
#include "mpi_logging.h"

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  SETRANK(world_rank);

  EXPECT_EQ_INT(VAL(1), VAL(1));

  PUTVAL_INT("nprocs", world_size);
  PUTVAL_INT("myrank", world_rank);

  LOG_BARRIER();

  for (int i=0; i<world_size; i++) {
    EXPECT_EQ_INT(VAL(world_size), VAL("nprocs", i));
    EXPECT_EQ_INT(VAL(i), VAL("myrank", i));
  }

  // Finalize the MPI environment.
  MPI_Finalize();
}
