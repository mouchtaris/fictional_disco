# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"
require "./cmake"

module Impls
  class CMake
    include ::CMake
    def initialize(@io, @conf)
    end
  end
end

struct Main
  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
  end

  def main
    Impls::CMake.new(STDOUT, @conf).call
  end

  def self.main
    Main.new(ARGV.dup).main
  end
end

Main.main
