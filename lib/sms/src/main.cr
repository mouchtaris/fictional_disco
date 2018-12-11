# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"

struct Main
  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
  end

  def self.main
    main = Main.new(ARGV.dup)
  end
end
